#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        string s;
        int q;
        cin >> s >> q;

        int n = s.size();
        set<int> occurrences;

        // Precompute all starting positions of "1100"
        for (int i = 0; i <= n - 4; ++i) {
            if (s.substr(i, 4) == "1100") {
                occurrences.insert(i);
            }
        }

        // Process queries
        while (q--) {
            int i;
            char v;
            cin >> i >> v;
            --i;  // Convert to 0-based index

            // Remove affected substrings from the set
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                if (s.substr(j, 4) == "1100") {
                    occurrences.erase(j);
                }
            }

            // Update the string
            s[i] = v;

            // Recheck affected substrings and add back valid ones
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                if (s.substr(j, 4) == "1100") {
                    occurrences.insert(j);
                }
            }

            // Output the result
            cout << (occurrences.empty() ? "NO" : "YES") << "\n";
        }
    }
}
