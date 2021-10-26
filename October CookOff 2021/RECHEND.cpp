#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define print(x) if(x)cout<<"YES\n";else cout<<"NO\n";
#define pb push_back
#define F first
#define S second
#define mod 998244353
using namespace __gnu_pbds;
using namespace std;
int dist(pair<int, int> &x, pair<int, int> &y) {
	return abs(x.F - y.F) + abs(x.S - y.S);
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int> > points;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		points.pb({x, y});
	}
	sort(all(points));
	for (int i = 1; i < n; i++) {
		ok |= (dist(points[i - 1], points[i]) > 2);
		if (points[i].S == 0 && !ok) {
			print(0);
			return;
		}
	}
	bool ok2 = false;
	reverse(all(points));
	for (int i = 1; i < n; i++) {
		ok2 |= (dist(points[i - 1], points[i]) > 2);
		if (points[i].S == n - 1 && !ok2) {
			print(0);
			return;
		}
	}
	print(ok && ok2);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	fastio;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}
