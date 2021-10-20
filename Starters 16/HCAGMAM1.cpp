#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff(a, c) for (int(a) = 0; (a) < (c); (a)++)
void solve()
{
    int x, y;
    cin >> x >> y;
    string str;
    cin >> str;
    ll cnt = 0;
    ll maxx = 0;
    ll ans = 0;
    ff(i, 30)
    {
        if (str[i] == '1')
        {
            ans += x;
            cnt++;
        }
        else
        {
            maxx = max(cnt, maxx);
            cnt = 0;
        }
    }
    maxx = max(cnt, maxx);
    ans += maxx * y;
    cout << ans << endl;
}
int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}
