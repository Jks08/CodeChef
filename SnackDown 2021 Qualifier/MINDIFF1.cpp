 #include <bits/stdc++.h>


using namespace std;
#define ll long long

#define ld long double
#define ff first
#define ss second
#define pb push_back
#define si set<int, greater<int>>
#define pll pair<ll, ll>
#define vl vector<ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define setbits(x) __buildin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define w(t) \
int t; \
cin >> t; \
while (t--)
#define lcm(x, y) (x * y) / __gcd(x, y)
#define gcd(x, y) __gcd(x, y)
bool prime(ll x)
{
if (x == 2)
{
return true;
}
if (x <= 1)
{
return false;
}
for (int i = 2; i < sqrt(x); i++)
{

if (x % i == 0)
{
return false;
}
}
return true;
}
void printv(vl v)
{
for (int i = 0; i < v.size(); i++)
{
cout << v[i] << " ";
}
cout << endl;
}
#ifndef ONLINE_JUDGE
#endif

string Y = "YES\n";
string N = "NO\n";



signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int t;
cin >> t;

for (int pop = 0; pop < t; pop++)
{
int n,m;
cin >> n>>m;
int indeg[n];
memset(indeg,0,sizeof(indeg));
vector<int> gr[n];

for (int i = 0; i < m; i++)
{
int el1,el2;
cin >> el1>>el2;
el1--;
el2--;
indeg[el1]++;
indeg[el2]++;
gr[el1].pb(el2);
gr[el2].pb(el1);
}
int ans=0;
map<int,unordered_set<int>> mpx;
bool vis[n];
for(int i=0;i<n;i++){
vis[i]=false;
mpx[indeg[i]].insert(i);
}
int arr[n];
for (int i = n; i > 0; i--)
{
auto kl = (mpx.begin()->second.begin());
int val = *kl;
mpx.begin()->second.erase(kl);
int xl = mpx.begin()->first;
if (mpx.begin()->second.size()==0)
{
mpx.erase(mpx.begin());
}
vis[val]=true;
arr[val] = i;
ans = max(ans,xl);
for(auto k:gr[val]){
if(vis[k]){
continue;
}
mpx[indeg[k]].erase(k);
if (mpx[indeg[k]].size()==0)
{
mpx.erase(indeg[k]);
}
indeg[k]--;
mpx[indeg[k]].insert(k);
}
}

cout<<ans<<"\n";
for (int i = 0; i < n; i++)
{
cout<<arr[i]<<" ";
}
cout<<"\n";

}

return 0;
}
