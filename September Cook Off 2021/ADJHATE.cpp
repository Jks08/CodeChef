#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll>odd,even;
    for(int i=0;i<n;i++){
        if(v[i]%2){
            odd.push_back(v[i]);
        }
        else{
            even.push_back(v[i]);
        }
    }
    if(odd.size()==0 || even.size()==0){
        cout<<"-1"<<"\n";
    }
    else{
        for(int i=0;i<odd.size();i++){
            cout<<odd[i]<<" ";
        }
        for(int i=0;i<even.size();i++){
            cout<<even[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
