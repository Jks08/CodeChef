#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	unsigned int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    char stat = '1';
	    long long int count = 0;
	    for(auto it=s.begin();it!=s.end();++it){
	        if((*it)!=stat){
	            count++;
	            stat=(*it);
	        }
	    }
	    cout<< count << "\n";
	}
	return 0;
}
