#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long int
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

  const int T = 1e6 + 5;
  long long phi[T];
  gp_hash_table<long long, long long> mp;
  int sz, spf[T], prime[T];
  void f() {
      memset(spf, 0, sizeof spf);
      phi[1] = 1; sz = 0;
      for (int i = 2; i < T; i++) {
          if (spf[i] == 0) phi[i] = i - 1, spf[i] = i, prime[sz++] = i;
          for (int j = 0; j < sz && i * prime[j] < T && prime[j] <= spf[i]; j++) {
              spf[i * prime[j]] = prime[j];
              if (i % prime[j] == 0) phi[i * prime[j]] = phi[i] * prime[j];
              else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
          }
      }
  }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin>>test;
    f();
   while(test--){            
            ll n;
            cin>>n;
            ll ans1=0,ans2=0;
            for(int i=2;i<=n;i++){
               ll temp=n/i;
               temp*=(phi[i]);
               ans2+=temp;
               temp*=(n/i);
               ans1+=temp;
            }
          
           
            ans1*=4LL;
            ans1+=n;
            ans2*=4LL;
            ans2+=n;
           
            ll ans=(ans1+ans2)/2;
            cout<<ans<<" ";
            
            cout<<"\n";

                     
   }
    return 0;
}
