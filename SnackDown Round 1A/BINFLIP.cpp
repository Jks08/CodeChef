#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
#define allsort(a) sort(a.begin(),a.end())

ll n,k;
void solve(){
    cin>>n>>k;
    if(k==0){
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        return;
    }
    if(k%2==0){
        cout<<"No"<<endl;;
        return;
    }
    ll sz=0;
    for(ll i=31;i>=0;i--){
        if(((1<<i)&k)!=0){
            sz=i+1;
            break;
        }
    }
    k=(k+(1<<sz)-1)/2;
    cout<<"Yes"<<endl;
    cout<<sz<<endl;
    int ans=1;
    vector<int> a;
    for(int i=sz-2;i>=0;i--){
        if(((1<<i)&k)!=0){
            a.push_back(ans);
            ans+=(1<<i);
        }
        else{
            ans-=(1<<i);
            a.push_back(ans);
        }
    }
    for(int i=sz-2;i>=0;i--)
        cout<<a[i]<<endl;
    cout<<ans<<endl;
}

int main(){
    FAST1;
    FAST2;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
