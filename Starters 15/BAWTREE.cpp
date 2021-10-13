#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sfor(i, l, r) for (int i = l; i <= r; ++i)
#define bfor(i, r, l) for (int i = r; i >= l; --i)
#define range(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using oset = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

struct S {
    ll a, b, c, d;
    S(ll a = 0, ll b = 0, ll c = 0, ll d = 0): a(a), b(b), c(c), d(d) {}
};

const ll INF = 1e9 + 10;
vector<vi> g;
vi a;
vector<S> dp;

void Dfs(int u = 0, int p = -1) {
    vector<pair<ll, ll>> dp1, dp2;
    dp1.emplace_back(0, INF);
    dp2.emplace_back(0, INF);
    for (int v: g[u]) {
        if (v != p) {
            Dfs(v, u);
            dp1.emplace_back(min(min(dp1.back().first + dp[v].a, dp1.back().second + dp[v].b), INF), min(min(dp1.back().first + dp[v].b, dp1.back().second + dp[v].a), INF));
            dp2.emplace_back(min(min(dp2.back().first + dp[v].c, dp2.back().second + dp[v].d), INF), min(min(dp2.back().first + dp[v].d, dp2.back().second + dp[v].c), INF));
        }
    }
    if (a[u] == 0)
        dp[u] = {dp1.back().first, min(dp2.back().second + 1, INF), dp1.back().second, min(dp2.back().first + 1, INF)};
    else
        dp[u] = {dp1.back().second, min(dp2.back().first + 1, INF), dp1.back().first, min(dp2.back().second + 1, INF)};
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.assign(n, vi(0));
        a.resize(n);
        dp.resize(n);
        sfor(i, 0, n - 1) cin >> a[i];
        sfor(i, 1, n - 1) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        Dfs();
        ll ans = min(dp[0].a, dp[0].b);
        if (ans == INF)
            cout << "-1\n";
        else
            cout << ans << '\n';
    }
}
