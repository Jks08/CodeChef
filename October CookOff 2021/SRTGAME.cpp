#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n), rp(n);
  vector<int> pot(n);


  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    rp[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> pot[i];
  }
  vector <bool> used(n, false);

  auto pp = p;
  auto ppot = pot;

  bool is_alice = true;
  vector<pair<int, int>> res;

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int len = 0;

    ll sum = 0;

    set <int> good;
    set <int> total;

    int v = i;
    while (!used[v]) {
      used[v] = true;
      sum += pot[v];

      int x = pot[v], y = pot[p[v]];

      if (x > 1 && y == 1) {
        good.insert(v);
      }
      total.insert(v);

      v = p[v];
      ++len;
    }

    if (sum < 2 * (len - 1)) {
      is_alice = false;
    }

    while (total.size() > 1) {
      int v;
      if (good.size()) {
        v = *good.begin();
      } else {
        v = *total.begin();
      }
      good.erase(v);
      good.erase(p[v]);
      good.erase(rp[v]);

      total.erase(p[v]);

      --pot[v], --pot[p[v]];

      res.pb({v, p[v]});

      int w = p[v];
      int u = p[p[v]];
      p[w] = w;
      rp[w] = w;

      p[v] = u;
      rp[u] = v;

      if (pot[v] > 1 && pot[u] == 1) {
        good.insert(v);
      }
      if (pot[rp[v]] > 1 && pot[v] == 1) {
        good.insert(rp[v]);
      }
    }
  }
  cout << (is_alice ? "Alice\n" : "Bob\n");
  cout << res.size() << "\n";

  for (auto t : res) {
    cout << t.x + 1 << " " << t.y + 1 << "\n";
    swap(pp[t.x], pp[t.y]);
    --ppot[t.x], --ppot[t.y];
  }
  for (int i = 1; i < n; ++i) {
    assert(pp[i - 1] < pp[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (is_alice) {
      assert(ppot[i] >= 0);
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

  //cout << "KEKW\n";

}
