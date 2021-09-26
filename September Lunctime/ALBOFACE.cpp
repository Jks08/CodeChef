#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<"Alice\n";
        }
        else{
            if(n&1LL){
                n=n-1;
                ll cnt=0;
                while(n){
                    ll cnt1=0;
                    while(n%2==0)
                    n=n/2,++cnt1;
                    n=n-1;
                    if(cnt1>=2)
                    ++cnt;
                }
                if(cnt>=2)
                cout<<"Bob\n";
                else{
                    if(cnt==0)
                    cout<<"Alice\n";
                    else
                    cout<<"Bob\n";
                }
            }
            else{
                ll cnt=0;
                while(n){
                    ll cnt1=0;
                    while(n%2==0)
                    n=n/2,++cnt1;
                    n=n-1;
                    if(cnt1>=2)
                    ++cnt;
                }
                if(cnt>=2)
                cout<<"Alice\n";
                else{
                    if(cnt==0)
                    cout<<"Bob\n";
                    else
                    cout<<"Alice\n";
                }
            }
        }
    }
}
