#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate integer power
ll int_pow(ll base, ll exp) {
    ll result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Function to count numbers up to r based on digit constraints
ll count(ll r) {
    vector<int> digits;

    // Extract digits of r
    while (r) {
        digits.push_back(r % 10);
        r /= 10;
    }
    reverse(digits.begin(), digits.end());
    
    int n = digits.size();
    ll result = 0;

    // First loop: Calculate contributions based on the leading digit
    for (int i = 1; i <= n; i++) {
        if (i == n) { // If it's the last digit
            result++;
            break;
        }
        result += int_pow(digits[0], n - 1 - i) * min(digits[0], digits[i]);
        if (digits[i] >= digits[0]) break; // Break if digit[i] is >= leading digit
    }

    // Second loop: Calculate contributions for smaller prefixes
    for (int i = 0; i < n; i++) {
        int max_digit = (i == 0 ? digits[0] - 1 : 9); // Leading digit has restrictions
        for (int j = 1; j <= max_digit; j++) {
            result += int_pow(j, n - 1 - i);
        }
    }

    return result;
}

int main() {
    ll l, r;
    cin >> l >> r;

    // Calculate the difference to find the count in the range [l, r]
    cout << count(r) - count(l - 1) << endl;
    return 0;
}
