#include <bits/stdc++.h>
using namespace std;

int setbits(int N){
    int ans=0;
    while(N>0){
        ans++;
        N=N>>1;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int N = setbits(n);
        int ans1 = n - pow(2,N-1) +1;
        int ans2 = pow(2,N-1)-pow(2,N-2);
        cout<<max(ans1,ans2)<<endl;
    }
	// your code goes here
	return 0;
}
