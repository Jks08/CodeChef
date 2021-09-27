#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        unordered_map<ll, ll> count;
        count[x]++;
        while (1) {
            ll n = lcm(x, y);
            ll val = n / y;
            x = val;
            if (val == 1) {
                cout << "YES" << "\n";
                break;
            }
            if (count[val] > 0) {
                cout << "NO" << "\n";
                break;
            }
            count[val]++;
        }
    }
}
