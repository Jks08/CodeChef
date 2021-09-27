#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	ll t;
    cin >> t;
    while (t--) {
        ll P, a, b, c, x, y;
        cin >> P >> a >> b >> c >> x >> y;
        ll anar = (a * x) + b;
        ll chakri = (a * y) + c;
        ll final = min(anar, chakri);
        ll ans = P / final;
        cout << ans  << '\n';
    }
	return 0;
}
