#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    vector<int> divisors;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            divisors.push_back(i);
            if (i != sum / i) {
                divisors.push_back(sum / i);
            }
        }
    }

    int min_thickness = n;
    for (int div : divisors) {
        int current_sum = 0;
        int max_segment_length = 0;
        int segment_length = 0;
        bool valid_split = true;
        
        for (int i = 0; i < n; i++) {
            current_sum += v[i];
            segment_length++;
            if (current_sum == div) {
                max_segment_length = max(max_segment_length, segment_length);
                current_sum = 0;
                segment_length = 0;
            } else if (current_sum > div) {
                valid_split = false;
                break;
            }
        }
        
        if (valid_split && current_sum == 0) {
            min_thickness = min(min_thickness, max_segment_length);
        }
    }

    cout << min_thickness << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
