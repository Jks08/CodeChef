#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h" 

using namespace std;
using namespace __gnu_pbds;

#define osl tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define osg tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef short unsigned su;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vpll> vvpll;

ll MOD=ll(1e9+7);
const double pi= 3.141592653589;
const double eps = 1e-12;
#define vv vector
#define pq priority_queue
#define us unordered_set 
#define ums unordered_multiset
#define um unordered_map 
#define umm unordered_multimap
#define f(i,a,b) for(reg ll i=a;i<b;i++)
#define fb(i,a,b) for(reg ll i=a;i>=b;i--)
#define fi(i,s) for(auto& i=s.begin();i!=s.end();i++)
#define fr(i,s) for(auto i=s.rbegin();i!=s.rend();i++)
#define fv(i,s) for( auto& i : s)
#define fp(k,v,s) for( auto& [k,v] : s)
#define ft(u,v,d,s) for( auto& [u,v,d] : s)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define sp(x) <<fixed<<setprecision(x)
#define mp make_pair
#define mt make_tuple
#define ts tuple_size
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define reg register
#define ff first
#define ss second
#define in insert
#define ig ignore
#define popcount(x) __builtin_popcountll(x)
#define czr(x) __builtin_ctzll(x)
#define czl(x) __builtin_clzll(x)
#define pow2(n) (n & (~(n - 1)))
#define clrp(x,i) (x & (1 << i)-1)
#define clrs(x,i) (x & ~((1 <<i)-1))
#define isp2(x) (x && !(x & x-1))
#define LSB(i) ((i) & -(i))
#define rzb(x) ((x)&-(x))
#define INF int(2e8)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define SET(name) freopen(name".txt", "r", stdin), freopen(name".txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define rez(s,n) s.clear();s.resize(n)
#define rot(s,l,r,d) rotate(s.begin()+l,s.begin()+l+d,s.begin()+r+1)
#define eqr(s,x) equal_range(all(s),x)
#define ubd(s,x) upper_bound(all(s),x)-s.begin()
#define lbd(s,x) lower_bound(all(s),x)-s.begin()
#define setv(s,x) memset(s,x,sizeof(s))
#define isin(s,x) (s.find(x)!=s.end())
#define isinv(s,x) (find(all(s),x)!=s.end())
#define isins(s,x) (s.find(x)!=string::npos)
#define ad(i,k) advance(i,k)
#define pc putchar
#define mat vv<vv<ld>> 
inline int gc(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s==e&&e==1048576){
    e=fread(buf, 1, 1048576, stdin);
    s=0;
  }
  if(s == e)return EOF;
  return buf[s++];
}
template<class T=int>
inline T read(){
    T c=gc(),t=1,n=0;
    if(c==' '||c=='\n'||c=='\r'||c=='\t'||c==EOF)c=gc();
    if(c=='-'){t=-1,c=gc();}
    while(isdigit(c)){n=n*10+c-'0',c=gc();}
    return n*t;
}
template<class T=int>
inline void write(T x){
    if (x<0){
        pc('-');
        x*=-1;
    }
    if(x<10)pc(x+'0');
    else{
        write(x/10);
        pc(x%10+'0');
    }
}
template<class T=int>
inline void print(T x,char c='\n'){
    write(x);
    pc(c);
}
int getSum(int BITree[], int index){
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[],int n,int index,int val){
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
template<class T>
ostream& operator<<(ostream& out,vv<T>&v){
    fv(i,v)out<<i<<" ";
    out<<ln;
    return out;
}
template<class T>
istream& operator>>(istream& inp,vv<T>&v){
    if(sz(v))fv(i,v)inp>>i;
    else{
        T t;
        string l;
        inp>>t;
        v.pb(t);
        getline(inp,l);
        istringstream iss(l);
        while(iss>>t)v.pb(t);
    }
    return inp;
}
template<class T>
istream& operator>>(istream& inp,vv<vv<T>>&A){
    fv(i,A)inp>>i;
    return inp;
}
template<class A,class B>
ostream& operator<<(ostream& out,pair<A,B>p){
    out<<"("<<p.ff<<","<<p.ss<<")";
    return out;
}
template<class A,class B>
istream& operator>>(istream& inp,pair<A,B>&p){
    inp>>p.ff>>p.ss;
    return inp;
}
template<class T>
ostream& operator<<(ostream& out,vv<vv<T>>A){
    fv(i,A)out<<i;
    return out;
}
int len(ll n){
    int l=0;
    while(n>0)l++,n/=10;
    return l;
}
ll MSB(ll n){
    int p=0;
    while(n)n>>=1,p++;
    return 1<<(p-1);
}
ll gcd(ll u,ll v){
    ll sft;
    if(u==0)return v;
    if(v==0)return u;
    sft=czr(u|v);
    u>>=czr(u);
    do{
        v>>=czr(v);
        if(u > v)swap(u, v);
        v-= u;
    }while(v!=0);
    return u<<sft;
}
template<class T>
vii imap(vv<T> a){
    vii t(sz(a));
    f(i,0,sz(a))t[a[i]-1]=i;
    return t;
}
int find_first_num_index(int &k, int n)
{
    if (n == 1) 
    {
        return 0;
    }
    n--;
    int first_num_index;
    int n_partial_fact = n;
 
    while (k >= n_partial_fact && n > 1) {
        n_partial_fact *= (n - 1);
        n--;
    }
    first_num_index = k / n_partial_fact;
    k %= n_partial_fact;
 
    return first_num_index;
}
vii find_kth_permutation(int n, int k)
{
    vector <int> Ans;
    set <int> S;
    for (int i = 1; i <= n; i++) 
    {
        S.insert(i);
    }
    auto itr = S.begin();
    k -= 1;
    for (int i = 0; i < n; i++) 
    {
        int index = find_first_num_index(k, n - i);
        advance(itr, index);
        Ans.push_back((*itr));
        S.erase(itr);
        itr = S.begin();
    }   
    return Ans;
}
int sum(vvii aux,int i,int j,int a,int b){
    int res=aux[i+a-1][j+b-1];
    if(i>0)res-=aux[i-1][j+b-1];
    if(j>0)res-=aux[i+a-1][j-1];
    if(i>0&&j>0)res+=aux[i-1][j-1];
    return res;
}
ll fpow(ll b, ll p){
    if (p==0)return 1;
    ll t=fpow(b,(p>>1));
    t=(t*t)%MOD;
    if (p&1)t*=b;
    return t%MOD;
}
ll fpow2(ll p){
  if (p==0)return 1;
  ll t=fpow2(p>>1);
  t=(t*t)%MOD;
  if (p&1)t<<1;
  return t%MOD;
}
template<class T>
T gcd(T u,T v){
    T shift;
    if(u==0)return v;
    if(v==0)return u;
    shift=czr(u|v);
    u>>=czr(u);
    do{
        v>>=czr(v);
        if(u > v)swap(u, v);
        v-= u;
    }while(v!=0);
    return u<<shift;
}
vll vec(ll x){
    vll y;
    while(x){
        y.pb(x%10);
        x/=10;
    }
    return y;
} 
ll power(int n){
    ll t=1;
    f(i,0,n)t*=10;
    return t;
}

void solve(){
    reg ll n,c,r=-1;
    vll a;
    cin>>n>>c>>a;
    sort(all(a));
    f(i,0,n)if(c<a[i]){r=i;break;}
    ll x=0,y=0;
    if(r!=-1){
        f(i,r,n)if((a[i]-c)%2==0)break;else y++;
        fb(i,r-1,0)if((c-a[i])%2==0)break;else x++;
    }
    else{fb(i,n-1,0)if((c-a[i])%2==0)break;else x++;}
    if(x+y<n)cout<<x+y<<" -1\n";else cout<<n<<" 1\n";
}
int main(){
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fast_cin();
    reg int u;
    cin>>u;
    while(u--)
    solve();
    return 0;
}
