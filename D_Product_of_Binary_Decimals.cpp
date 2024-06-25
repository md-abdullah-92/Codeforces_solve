#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Generate all binary decimal numbers up to a certain limit
vector<int> generateBinaryDecimals(int limit) {
    vector<int> binaryDecimals;
    for (int i = 1; i <= limit; ++i) {
        int num = i;
        bool isBinaryDecimal = true;
        while (num > 0) {
            int digit = num % 10;
            if (digit != 0 && digit != 1) {
                isBinaryDecimal = false;
                break;
            }
            num /= 10;
        }
        if (isBinaryDecimal) {
            binaryDecimals.push_back(i);
        }
    }
    return binaryDecimals;
}

// Check if a number can be represented as a product of binary decimals using BFS
bool canBeProductOfBinaryDecimals(int n, const vector<int>& binaryDecimals) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(1); // Start with the smallest binary decimal, which is 1
    visited.insert(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int bd : binaryDecimals) {
            if (curr * bd > n) break;
            int next = curr * bd;
            if (next == n) return true;
            if (next < n && visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> binaryDecimals = generateBinaryDecimals(100000); // Generate binary decimals up to 100000

    while (t--) {
        int n;
        cin >> n;
        if (canBeProductOfBinaryDecimals(n, binaryDecimals)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
