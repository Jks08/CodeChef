#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t,n,k,i,j;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll>v(n+1);
        for(i=1; i<=n && k>0; i++, k--){
            v[i]=i;
        }
        for(j=i; j<n; j++){
            v[j]=j+1;
        }
        if(i<=n){
        v[n] = i;
        }
        ll f=0;
        for(j=i; j<=n; j++){
            if(v[j]==j){
                f=1;
                break;
            }
        }
        if(f==1){
            cout<<"-1";
        }else{
            for(i=1; i<=n; i++){
                cout<<v[i]<<" ";
            }
        }
        cout<<"\n";
    }
}
