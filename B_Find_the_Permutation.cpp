#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Function to solve a single test case
void solveTestCase() 
{
    int numNodes;
    cin >> numNodes;

    // Input adjacency matrix as strings
    vector<string> adjacencyMatrix(numNodes);
    for (int rowIndex = 0; rowIndex < numNodes; rowIndex++) {
        cin >> adjacencyMatrix[rowIndex];
    }

    // Initialize a permutation from 0 to numNodes-1
    vector<int> nodeOrder(numNodes);
    for (int nodeIndex = 0; nodeIndex < numNodes; nodeIndex++) {
        nodeOrder[nodeIndex] = nodeIndex;
    }

    // Sort the permutation based on the adjacency matrix
    sort(nodeOrder.begin(), nodeOrder.end(), [&](int firstNode, int secondNode) {
        if (firstNode < secondNode) {
            return (adjacencyMatrix[firstNode][secondNode] == '1'); 
            // firstNode comes before secondNode if adjacencyMatrix[firstNode][secondNode] == '1'
        }
        return (adjacencyMatrix[firstNode][secondNode] == '0');
    });

    // Output the permutation in 1-based indexing
    for (int nodeIndex = 0; nodeIndex < numNodes; nodeIndex++) {
        cout << nodeOrder[nodeIndex] + 1 << " ";
    }
    cout << endl;

    return;
}

int32_t main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solveTestCase();
    }
}
