#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 1; // Extend range to include N
vector<int> sum_of_divisors(N, 0);

// Precomputes the sum of divisors for every number up to N-1
void precompute_divisor_sums() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            sum_of_divisors[j] += i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n < N) {
       int k= sum_of_divisors[n]-n;
       if(k>n) cout<<"abundant\n";
       else if(k<n) cout<<"deficient\n";
       else cout<<"perfect\n";
    } else {
        cout << "Number out of range!" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precompute_divisor_sums();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
