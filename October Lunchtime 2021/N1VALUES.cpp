#include <bits/stdc++.h>
using namespace std;
#define tc ll t sc cin >> t sc while (t--)
#define sc ;
#define endl '\n'
#define ll long long int

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
        ll n;
        cin >> n;
        cout << 1 << " ";
        for(ll i=0;i<n;i++){
            ll p=((ll)1<<i);
                cout <<p<<" ";
            }
            cout << endl;
        }
        
    
    return 0;
}
