#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<bitset>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<chrono>
#include<list>
#include<climits>
#include<iomanip>
using namespace std;

#define ll long long int
bool rcomp(ll a,ll b){
    return a>b;
}

#define ff first
#define ss second

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    vector<ll> arr(n,0),brr(n,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    for(ll i=0;i<n;i++) cin>>brr[i];

    vector<vector<ll>> pos(m+3);
    for(ll i=0;i<n;i++) pos[arr[i]].push_back({brr[i]});
    for(ll i=0;i<=m;i++) sort(pos[i].begin(),pos[i].end(),rcomp);


    vector<ll> visited(m+2,0),topics(m+2,0);
    multiset<pair<ll,ll>> s;
    for(ll i=0;i<=m+1;i++) if(pos[i].size()){
        s.insert({pos[i].back(),i});
        pos[i].pop_back();
    }

    while(k>0 and !s.empty()){
        auto elem = *(s.begin());
        if(k<elem.ff) break;
        k-=elem.ff;
        s.erase(s.begin());
        if(visited[elem.ss]==0) topics[elem.ss]+=1,visited[elem.ss]=1;
        else topics[elem.ss]+=2;
        if(pos[elem.ss].size()>=2){
            auto itr1 = pos[elem.ss].back(); pos[elem.ss].pop_back();
            auto itr2 = pos[elem.ss].back(); pos[elem.ss].pop_back();
            s.insert({itr1+itr2,elem.ss});
        }
    }

    ll ans = 0;
    for(ll i=0;i<=m;i++) ans+=(topics[i]+1)/2;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--) solve();
}
