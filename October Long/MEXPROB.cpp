#include <bits/stdc++.h>
#define N int(2e6+10)
#define ll long long int
using namespace std;
int dp[N], a[N], n, t, l ,u, mid;
ll ans, k;
ll f(int x) {
	// mex <= x
	ans = 0ll;
	for(int i=0; i <= x; i++){
		dp[i] =  0;
	}
	for(int i=0, j = 0, cnt = 0; i < n;i++) {	
		if(a[i] <= x) {
			if(!dp[a[i]])
				cnt++;
			dp[a[i]] ++;
		}
		while(cnt == x + 1) {
			if(a[j] <= x) {
				dp[a[j]] --;
				if(!dp[a[j]])
					cnt--;
			}
			j++;
		}
		ans += 1ll * (i - j + 1);
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(10);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		l = 0, u = n, mid;
		while(l < u) {
			mid = l + (u-l) / 2;
			if(f(mid) < k)
				l = mid + 1;
			else
				u = mid;
		}
		cout << l << endl;
	}
	return 0;
}
