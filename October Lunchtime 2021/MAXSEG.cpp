#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	vector<ll> ra(n + 1);
	rep(i, n)ra[i + 1] = ra[i] + a[i];
	vector<int> b(n);
	rep(i, n)cin >> b[i];
	vector<int> rb(n + 1);
	rep(i, n)rb[i + 1] = rb[i] + b[i];
	int tmp = 0;
	int sz = 1;
	while (sz <= n) {
		sz *= 2; tmp++;
	}
	vector<vector<int>> nex(n+1, vector<int>(tmp,n));
	vector<vector<int>> ad(n+1, vector<int>(tmp));
	rep(i, n)if (b[i]) {
		int cur = i + 1;
		int le = i + 1;
		while (cur < n && b[cur] == 0) {
			cur++;
		}
		int ri = cur;
		set<LP> st;
		ll sum = 0;
		st.insert({ sum,i + 1 });
		for (int j = le; j < ri; j++) {
			sum += a[j];
			st.insert({ sum,j + 1 });
		}
		int chk = ri;
		ll ma = 0;
		ll s = 0;
		for (int j = ri - 1; j >= le; j--) {
			s += a[j];
			if (ma < s) {
				ma = s;
				chk = j;
			}
		}
		int l = i - 1;
		while (l >= 0 && b[l] == 0)l--;
		s = 0;
		for (int j = i; j > l; j--) {
			s += a[j];
			if (s + (*--st.end()).first < 0) {
				nex[j][0] = chk;
				ad[j][0] = 0;
			}
			else {
				LP p = { -s,-1 };
				auto itr = st.lower_bound(p);
				nex[j][0] = (*itr).second;
				ad[j][0] = 1;
			}
		}
	}
	rep(j, tmp-1) {
		rep(i, n+1) {
			nex[i][j + 1] = nex[nex[i][j]][j];
			ad[i][j + 1] = ad[i][j] + ad[nex[i][j]][j];
		}
	}
	rep(i, q) {
		int l, r; cin >> l >> r; l--; r--;
		int num = rb[r + 1] - rb[l];
		if (num == 0) {
			cout << 0 << "\n"; continue;
		}
		int cur = l;
		int ans = 0;
		rep(j, tmp)if ((num-1) & (1 << j)) {
			ans += ad[cur][j];
			cur = nex[cur][j];
		}
		if (ra[r + 1] - ra[cur] >= 0)ans++;
		cout << ans << "\n";

	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}

