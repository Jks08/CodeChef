#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rsz resize
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define trav(a,x) for (auto& a: x)
#define MOD 998244353
#define INF 1e16
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
#define deb(var) do{cout << #var << " : "; view(var);}while(0)
template<typename T> void view(T e) {cout << e << endl;}
void view(vector<string>& v) {cout << endl; for (auto& s : v) {view(s);} cout << endl;}
template<typename T> void view(vector<T>& v) {for (auto& e : v) {cout << e << " ";} cout << endl;}
template<typename T> void view(vector<vector<T>>& vv) {cout << endl; for (auto& v : vv) {view(v);}}
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

void start()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int len(int num) {
	int res = 0;
	while (num > 0) {
		num /= 10;
		res++;
	}
	return max(res, 1ll);
}
int32_t main() {
	start();
	int t;
	cin >> t;
	int power[10];
	power[0] = 1ll;
	for (int i = 1; i < 10; i++) {
		power[i] = 10ll * power[i - 1];
	}
	while (t--) {
		int n, L, R;
		cin >> n >> L >> R;
		vector<int> A[9];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			A[len(x)].push_back(x);
		}
		for (int i = 1; i <= 8; i++) {
			sort(A[i].begin(), A[i].end());
		}
		int ans = 0;
		int lo = len(L);
		int hi = len(R);
		for (int i = 1; i <= 8; i++) {
			for (int j = 0; j < (int)A[i].size(); j++) {
				for (int k = 1; k <= 8; k++) {
					if (i + k >= lo && i + k <= hi) {
						int lo_end = -1;
						if (A[i][j] > L / power[k]) {
							lo_end = 0;
						}
						else {
							int st = 0;
							int fin = (int)A[k].size() - 1;
							while (st <= fin) {
								int mid = (st + fin) / 2;
								if (A[i][j]*power[k] + A[k][mid] >= L) {
									fin = mid - 1;
									lo_end = mid;
								}
								else {
									st = mid + 1;
								}
							}
						}
						int hi_end = -1;
						if (A[i][j] < R / power[k]) {
							hi_end = (int)A[k].size() - 1;
						}
						else {
							int st = 0;
							int fin = (int)A[k].size() - 1;
							while (st <= fin) {
								int mid = (st + fin) / 2;
								if (A[i][j]*power[k] + A[k][mid] <= R) {
									st = mid + 1;
									hi_end = mid;
								}
								else {
									fin = mid - 1;
								}
							}
						}
						if (lo_end != -1 && hi_end != -1) {
							ans += max(hi_end - lo_end + 1, 0ll);
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
