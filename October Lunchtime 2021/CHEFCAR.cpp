#include <bits/stdc++.h>
using namespace std;
#define tc ll t sc cin >> t sc while (t--)
#define ff first
#define vp vector<pair<ll,ll>>
#define sc ;
#define ss second
#define srt sort
#define endl '\n'
#define pb push_back
#define pp pop_back
#define mp make_pair
#define modulo 1000000007
#define ll long long int
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

typedef unsigned int ui;
typedef unsigned long long int ul;

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    tc
    {
       ll a,b;
       cin >> a >> b;
       ll ans=(ll)a*(a-1)/2;
       cout << ans << " ";
       if(b>=a-1){
           cout << a-1<< endl;
       }
       else
       {
           ll rem=a-b;
           ll ans1=(ll)rem*(rem+1)/2;
           ans1=ans1+(b-1);
           cout << ans1 << endl;
       }
    }
    return 0;
}
