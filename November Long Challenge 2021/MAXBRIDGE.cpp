#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        for(ll i=1;i<=n-1;i++) cout<<i<<" "<<i+1<<endl;
        k-=(n-1);
        for(ll i=3;i<=n;i++){
            for(ll j=i-2;j>=1;j--){
                if(k==0) break;
                k--;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
