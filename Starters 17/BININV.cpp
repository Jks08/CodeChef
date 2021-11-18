#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define ff          first
#define ss          second
#define pb          push_back
#define endl        '\n'


signed main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



   int tc;
   cin >> tc;

   while(tc--){

       ll n, m;
       cin >> n >> m;
       vector <pair<ll,string>> v;

       for(int i=0;i<n;i++){
           string s;
           cin>>s;
           ll cnt=0;
           for(int j=0;j<m;j++)
               if(s[j]=='0'){
                   cnt++;
               }
               v.pb({-cnt,s});
       }
       sort(v.begin(), v.end());
       
       string a="";
       for(int i=0;i<n;i++){
           a += v[i].ss;
       }
       ll cnt=0;
       for(int i=0;i<n*m;i++)
           if(a[i]=='0'){
               cnt++;
           }
           ll ans=0;
           for(int i=0;i<n*m;i++){
               if(a[i]=='1'){
                   ans+=cnt;
               }
               else{
                   cnt--;
               }
           }
           
           cout << ans << endl;




   }

    return 0;
}
