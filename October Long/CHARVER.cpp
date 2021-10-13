#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 1010;
const int MM = 15;
const int mod = 998244353;

int mat[MM][NN];
int dan[NN][NN];
int a[NN];

void update(int &u, int v) {
	u += v;
	if(u >= mod) u -= mod;
}

void solve() {
	int m; cin >> m;
	for(int i = 0; i < m; i ++) cin >> a[i];
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) scanf("%d", &dan[i][j]);
	}
	
	for(int i = 0; i < n; i ++) mat[0][i] = rand();
	for(int i = 1; i < m; i ++) {
		for(int j = 0; j < n; j ++) {
			mat[i][j] = 0;
			for(int k = 0; k < n; k ++) {
				update(mat[i][j], (INT) mat[i - 1][k] * dan[k][j] % mod);
			}
		}
	}
	
	for(int i = 0; i < n; i ++) {
		int sum = 0;
		for(int j = 0; j < m; j ++) update(sum, (INT)mat[j][i] * a[j] % mod);
		if(sum) {
			puts("NO");
			return ;
		}
	}
	puts("YES");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in ","r ",stdin);
	freopen("out.out ","w ",stdout);
#endif
	srand(time(0));
	int t; cin >> t;
	while(t --) solve();
	
	return 0;
}
