#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to decompose cycles in the permutation
vector<vector<int>> decompose_cycles(int N, const vector<int>& P) {
    vector<vector<int>> cycles;
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            vector<int> cycle;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                cycle.push_back(x);
                x = P[x - 1];
            }
            cycles.push_back(cycle);
        }
    }

    return cycles;
}

// Function to calculate the minimum cost to merge cycles into one
int calculate_min_cost(vector<vector<int>>& cycles) {
    if (cycles.size() == 1) {
        // Already a single cycle
        return 0;
    }

    int total_cost = 0;

    while (cycles.size() > 1) {
        // Sort cycles by length
        sort(cycles.begin(), cycles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a.size() < b.size();
        });

        // Merge the two smallest cycles
        vector<int> c1 = cycles[0];
        vector<int> c2 = cycles[1];
        int merge_cost = c1.size() + c2.size();
        total_cost += merge_cost;

        // Create the new merged cycle
        vector<int> merged_cycle = c1;
        merged_cycle.insert(merged_cycle.end(), c2.begin(), c2.end());
        
        // Remove the first two cycles and add the merged cycle
        cycles.erase(cycles.begin(), cycles.begin() + 2);
        cycles.push_back(merged_cycle);
    }

    return total_cost;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }

        // Step 1: Decompose cycles
        vector<vector<int>> cycles = decompose_cycles(N, P);

        // Step 2: Calculate the minimum cost to merge cycles
        int result = calculate_min_cost(cycles);

        // Output the result
        cout << result << endl;
    }

    return 0;
}
