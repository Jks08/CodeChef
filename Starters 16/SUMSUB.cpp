#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int MOD = 1e9+7;

void solve(){
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i = 0 ; i < n ; i++){
       cin>>v[i];
   }

   //Pre Calculations.........
   vector<int> calculate(n,0);
   int sum = 1;
   int j = 2;
   calculate[n-1] = v[n-1];
   for(int i = n-2 ; i >= 0 ; i--){
        sum = (sum + j)%MOD;
        calculate[i] = (sum*v[i])%MOD;
        calculate[i] %= MOD;
        j++;
   }
   debug(calculate);

   // FOR NGE................
   stack<int> s;
   vector<int> NGE(n,-1);
   s.push(n-1);
   for(int i = n-2 ; i >= 0 ; i--){
        if(v[i] < v[s.top()]){
            NGE[i] = s.top();
            s.push(i);
        }else{
            while(!s.empty() && v[i] > v[s.top()]){
                s.pop();
            }
            if(s.empty())
                s.push(i);
            else{
                NGE[i] = s.top();
                s.push(i);
            }
        }
   }
   debug(NGE);

   //Main Logic..............
   vector<int> DP(n,0);
   int ans = 0;
   for(int i = n-1 ; i >= 0 ; i--){
        if(NGE[i] == -1){
            DP[i] += calculate[i];
        }else{
            int s_u = n-NGE[i];
            int s_u2 = (s_u)*(s_u+1)/2;
            s_u2 %= MOD;
            int s_u3 = (s_u2*v[i])%MOD;
            // debug(s_u3);
            // debug(calculate[i]);
            DP[i] = (calculate[i] - s_u3 + DP[NGE[i]] + MOD)%MOD;
        }
        debug(DP[i]);
   }
   for(int i = 0 ; i < n ; i++){
        ans += DP[i];
        ans = ans%MOD;
   }
   cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

