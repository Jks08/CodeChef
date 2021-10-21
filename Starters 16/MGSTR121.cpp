#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 1

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

int pref[26][100010];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0 ; i < 26 ; i++) pref[i][0] = 0;
    pref[s[0] - 'A'][0]++;
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
            pref[j][i] = pref[j][i - 1];
        pref[s[i] - 'A'][i]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        --l; --r;
        if (r - l + 1 < k)
        {
            cout << "No\n";
            continue;
        }
        string ss;
        vector<int> frek(26,0);
        for (int i = 0 ; i < 26 ; i++)
            frek[i] = pref[i][r] - (l == 0 ? 0 : pref[i][l - 1]);
        int mx = *max_element(frek.begin(),frek.end());
        if (mx > k)
        {
            cout << "No\n";
            continue;
        }
        for (int i = l ; i <= r ; i++) ss += s[i];
        cout << "Yes\n";
        if (mx == k)
        {
            for (int i = 25 ; i >= 0 ; i--)
            {
                for (int j = 0 ; j < frek[i] ; j++)
                    cout << (char)('A' + i);
            }
            cout << endl;
            continue;
        }
        else
        {
            sort(ss.begin(),ss.end());
            // cerr << ss << endl;
            string awal,akhir;
            for (int i = 0 ; i < ss.length() ; i++)
            {
                if (i < k)
                    akhir += ss[i];
                else
                    awal += ss[i];
            }
            reverse(awal.begin(),awal.end());
            string ans = awal + akhir;
            cout << ans << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}
