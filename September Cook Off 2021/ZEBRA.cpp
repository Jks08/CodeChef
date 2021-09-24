#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char res=s[0];
    int count=0;
    for(int i=1;i<n;i++){
        if(res!=s[i]){
            count++;
            res=s[i];
        }
    }
    if(count<k){
        cout<<-1<<"\n";
        return;
    }
    if(s[0]=='0'){
        if(k%2){
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='1'){
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
        else{
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='0'){
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
    }
    else{
        if(k%2){
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='0'){
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
        else{
            for(int i=s.size();i>=0;i--){
                if(s[i]=='1'){
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
