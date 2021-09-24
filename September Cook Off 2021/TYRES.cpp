#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
void solve(); 
int main() {    
    ll int t=1;
    cin >> t;
    while (t--) { 
        solve(); 
        cout << "\n"; 
    }    
    int z; 
    cin>>z; 
    return 0; 
} 
void solve(){ 
    ll n;
    cin>>n; 
    if(n%4 == 0) cout<<"NO"; 
    else cout<<"YES"; 
}
