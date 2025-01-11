#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5; // Adjust based on constraints
vector<int> divisor_count(MAX_N);

void precompute_divisors() {
    for (int i = 1; i < MAX_N; i++) {
        for (int j = i; j < MAX_N; j += i) {
            divisor_count[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << divisor_count[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_divisors(); // Precompute all divisor counts

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
