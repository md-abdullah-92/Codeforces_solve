#include <bits/stdc++.h>
using namespace std;

long long evaluateExpression(const string &s, const vector<char> &ops) {
    vector<long long> nums;
    vector<char> operators;

    long long currentNum = s[0] - '0';
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '+') {
            nums.push_back(currentNum);
            operators.push_back('+');
            currentNum = s[i + 1] - '0';
        } else { // ops[i] == '*'
            currentNum *= (s[i + 1] - '0');
        }
    }
    nums.push_back(currentNum);

    // Now evaluate the addition
    long long result = 0;
    for (long long num : nums) {
        result += num;
    }

    return result;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    long long minResult = LLONG_MAX;

    // There are (n-1) positions and each can either be '+' or '*'
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        vector<char> ops(n - 1);
        for (int i = 0; i < (n - 1); ++i) {
            if (mask & (1 << i)) {
                ops[i] = '*';
            } else {
                ops[i] = '+';
            }
        }
        long long result = evaluateExpression(s, ops);
        minResult = min(minResult, result);
    }

    cout << minResult << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
