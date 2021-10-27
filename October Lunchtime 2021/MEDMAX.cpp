#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int fun(int mid, int index, vector<int> vec, int n){
    int num=0, m;
    if(mid%(index-1))
    m=mid/(index-1);
    else
    m=mid/(index-1)-1;
    for(int i=0; i<m; i++){
        num+=vec[mid+i];
    }
    for(int i=m+1; i<=n; i++){
        num+=vec[index*i];
    }
    return num;
}

int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>vec;
        vec.push_back(0);
        for(int i=0; i<n*n; i++){
            int num;
            cin>>num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        int ind;
        if(n%2)
        ind=(n+1)/2;
        else
        ind=(n+1)/2 +1;
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=vec[ind*(i+1)];
        }
        if(sum>k){
            cout<<"-1"<<"\n";
        }
        else if(n==1)
        cout<<vec[1]<<"\n";
        else{
            int lo=ind, hi=(ind-1)*n +2, mid;
            while(hi>lo){
                mid=(lo+hi)/2;
                if(fun(mid, ind, vec, n)<=k){
                    ans=mid;
                    lo=mid+1;
                }
                else{
                    hi=mid;
                }
            }
            cout<<vec[ans]<<"\n";
        }
    }
    return 0;
}
