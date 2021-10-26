#include<bits/stdc++.h>
#define  ull unsigned long long int
#define ll long long 
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define pb push_back
#define Setbit(n)   __builtin_popcountll(n)
#define ms(a,x) memset(a,x,sizeof(a))
#define sp(n,a) cout<<fixed<<setprecision(n)<<a
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define aca(a,n,x) accumulate(a,a+n,x)
#define pi 3.14159265358979323846
const ull INF=1e18;
const  ll  N=200007;
using namespace std;
int64_t lol;
#define MOD 998244353
#define MAX  10000000

ll POW(ll x,ll y){
      ll r=1;
      for(; y ; x= (x % MOD * x % MOD ) % MOD  ,y>>=1)
            if(y&1) r = (r % MOD * x % MOD) % MOD ;
      return r;
}
 
 
 
bool cmp(pair<ll,ll> &a ,pair<ll,ll> &b){
          return a.ss<b.ss;
    }
    
 bool cmp1(ll a ,ll b){
          return a>b;
    }
    
 
ll lcm(ll a,ll b){
    ll di=__gcd(a,b);
    return (a*b)/di;
}
void solve(){

ll  n,m,i,j;

 ll k=1e18+1;
       cout<<"? "<<k<<endl;
       cin>>n;
       k-=(n+1);
       cout<<"? "<<k<<endl;
       cin>>n;
       cout<<"! "<<(n+1)<<endl;

}

int  main(){

ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

  

int t;

cin>>t;
while(t--){

solve();
 
}
return 0;
}
