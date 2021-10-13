#include <bits/stdc++.h>
using namespace std;

#define FAST 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll 		long long
#define pii 	pair<int, int>
#define pll 	pair<ll, ll>
#define vi 		vector<int>
#define vll 	vector<ll>
#define vpi 	vector<pii>
#define vpll 	vector<pll>

template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define EPS 	(1e-8)
#define INF 	0x3f3f3f3f
#define MN 		800010
#define logN 	22
#define MOD		998244353 
#define X 		first
#define Y 		second
#define YX		second.first
#define YY		second.second
#define pb 		push_back
#define eb 		emplace_back
#define mp 		make_pair

#define spa 	<< " " <<
#define endl 	'\n'

#define rep(X,Y) 		for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) 	for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) 		for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) 	for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))

#define all(a)  		(a).begin(),(a).end()
#define allr(a)  		(a).rbegin(),(a).rend()
#define _unique(x) 		sort(all(x)), x.erase(unique(all(x)), x.end())


template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}

template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
}


ll 	pow2(int i) 		{ return 1LL << i; }
int topbit(signed t) 	{ return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) 		{ return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) 	{ return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) 		{ return a == 0 ? 64 : __builtin_ctzll(a); }
ll  allbit(ll n) 		{ return (1LL << n) - 1; }
int popcount(signed t) 	{ return __builtin_popcount(t); }
int popcount(ll t) 		{ return __builtin_popcountll(t); }
bool ispow2(int i) 		{ return i && (i & -i) == i; }

int a[MN];
ll cn[MN];
ll p[MN];


ll rev (ll x)
{
	int res = 1;
	int y = MOD - 2;
	
	while (y > 0)
	{
	    if (y & 1) res = x * res % MOD;
	    x = x * x % MOD;
	    y >>= 1;
	}
	
	return res;
}

void Solve()
{
	int i, j, n, sz;
	ll cnt, tmp, ans;
	cin >> n;
	rep(i, n) 
		cin >> a[i];
	sort(a, a + n);
	sz = 0;
	cn[0] = 1;
	reps(i, 1, n)
	{
		if (a[i] == a[i - 1])
			cn[sz]++;
		else
			cn[++sz] = 1;
	}

	p[sz] = 1;
	cnt = 0;
	ans = (p[sz] * cn[sz]) % MOD;
	rrep(i, sz)
	{
		tmp = (p[i + 1] * cnt + cn[i + 1] * (p[i + 1] + 1)) % MOD;
		p[i] = (tmp * rev(cnt + cn[i + 1])) % MOD;
		cnt = (cnt + cn[i + 1]) % MOD;
		ans = (ans + p[i] * cn[i]) % MOD;
	}
	ans = (ans * rev(n)) % MOD;
	cout << ans << endl;
}

int main()
{
	FAST

	int tc;
	cin >> tc;
	while (tc--)
	{
		Solve();
	}
	return 0;
}
