#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll c;
        cin>>c;
        if(c==0){
            cout<<2<<"\n"<<1<<" "<<1<<"\n";
            continue;
        }
        ll ans=0;
        vector<ll>v;
        while(c){
            ll temp=1;
            while((temp-1)<c){
                temp=temp*2;
            }
            ans++;
            v.push_back(temp-1);
            //cout<<temp-1<<" ";
            c=(temp-1)-c;
        }
        cout<<ans<<"\n";
        for(auto &i:v)cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
