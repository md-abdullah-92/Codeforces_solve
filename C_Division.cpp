#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> divisors;
    vector<ll> ans;
    ll k = m;
    if (n % m) {
        cout << n << endl;
        return;
    }
    for (ll i = 2; i * i <= m; i++) {
        while (k % i == 0) {
            divisors.push_back(i);
            k /= i;
        }
    }
    if (k > 1) {
        divisors.push_back(k);
    }
    ll mx = 0;
    for (ll p : divisors) {
        k = n;
        while (k % m == 0) {
            k /= p;
        }
        mx = max(k, mx);
    }
    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
