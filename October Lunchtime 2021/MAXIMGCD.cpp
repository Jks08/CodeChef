#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
const int maxn = 1000100;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

void solve(int tc) {
	int n;
	cin >> n;
	vector <ll> v(n);
	rep(i, 0, n) cin >> v[i];
	if (n == 2) {
		cout << v[0] * v[1] << "\n";
		return;
	}
	
	vector <ull> primes;
	rep(i, 0, 3) {
		auto fac = factor(v[i]);
		trav(p, fac) primes.pb(p);
	}
	
	sort(all(primes));
	auto it = unique(all(primes));
    primes.resize(distance(primes.begin(), it));
  
	vector <vector<pii> > data(sz(primes), vector<pii>(3, make_pair(100, 100)));
	rep(j, 0, sz(primes)) {
		ll p = primes[j];
		rep(i, 0, n) {
			ll tmp = v[i];
			int cnt = 0;
			while (tmp % p == 0) tmp /= p, ++cnt;
			rep(ktore, 0, 3) {
				if (cnt < data[j][ktore].e1) {
					for (int l = 2; l > ktore; --l) data[j][l] = data[j][l - 1];
					data[j][ktore] = {cnt, i};
					break;
				}
			}
			
		}
		
		debug(p, data[j]);
	}
	vector <vector<ll>> benefit(sz(primes));
	rep(j, 0, sz(primes)) {
		benefit[j].clear();
		rep(i, 0, 3) benefit[j].pb(modpow(primes[j], data[j][i].e1, LLONG_MAX));
	}
	
	debug(benefit);
	ll current = 1;
	rep(j, 0, sz(primes)) current *= benefit[j][0];
	set<pii> visited;
	
	auto same = [&](pii a, pii b) -> bool {
		if (a.e1 == b.e1 && a.e2 == b.e2) return true;
		if (a.e1 == b.e2 && a.e2 == b.e1) return true;
		return false;
	};
	
	ull best = current;
	
	auto check = [&](int i1, int i2) {
		if (i1 == i2) return;
		pii moje = {i1, i2};
		if (visited.find(moje) != visited.end()) return;
		visited.insert(moje);
		ull res = current;
		rep(i, 0, sz(primes)) {
			if (same(moje, make_pair(data[i][0].e2, data[i][1].e2))) { // jest szansa na duzy zysk
				res /= benefit[i][0];
				res *= modpow(primes[i], min(data[i][0].e1 + data[i][1].e1, data[i][2].e1), LLONG_MAX);
			}
			else { //na pewno nie bedzie duzego zysku, ale moze byc maly
				if (i1 == data[i][0].e2 || i2 == data[i][0].e2) {
					res /= benefit[i][0];
					res *= benefit[i][1];
				}
			}
		}
		best = max(best, res);
	};
	rep(a, 0, sz(primes)) {
		rep(b, a, sz(primes)) {
			check(data[a][0].e2, data[b][0].e2);
			check(data[a][0].e2, data[b][1].e2);
			check(data[a][1].e2, data[b][0].e2);
			check(data[a][1].e2, data[b][1].e2);
		}
	}
	
	cout << best << "\n";
}

int main() {
	boost;
	int tests;
	cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}
