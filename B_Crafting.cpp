#include <bits/stdc++.h>

using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int num_elements;
    cin >> num_elements;
    vector<int> original_values(num_elements), target_values(num_elements);
    int total_difference = 0;
    map<int, int> frequency_map;

    for (int i = 0; i < num_elements; i++) {
        cin >> original_values[i];
    }

    int adjustments = 0, excess_difference = 0;

    for (int i = 0; i < num_elements; i++) {
        cin >> target_values[i];

        if (target_values[i] > original_values[i]) {
            total_difference += target_values[i] - original_values[i];
            adjustments++;
            original_values[i] += 2 * total_difference;
        }
    }

    if (adjustments > 1) {
        no;
        return;
    }

    int required_difference = total_difference;

    for (int i = 0; i < num_elements; i++) {
        if (target_values[i] > (original_values[i] - required_difference)) {
            no;
            return;
        }
    }

    yes;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}
