#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    
    if (n <= 2) {
        // If n is <= 2, we directly print the number because there's only one number to read
        int num;
        cin >> num;
        cout << num << endl;
        return;
    }

    string s;
    cin >> s;

    int min_number = INT_MAX;
    int min_position = -1;

    // Iterate through the string to find the minimum 2-digit number
    for (int i = 0; i <= n - 2; ++i) {
        // Convert the substring of length 2 starting from index i into an integer
        int current_number = stoi(s.substr(i, 2));
        
        // Update the minimum number and its position
        if (current_number < min_number) {
            min_number = current_number;
            min_position = i;
        }
    }
    
    if(min_number < 10) {
        if(n >= 4) {
            cout << 0 << endl;  
            return;
        } else {
            int p = s[0] - '0';
            if(p==0||p==1||min_number==0||min_number==1) 
            cout << min_number * p << endl;
            else
            cout << min_number + p << endl;
            return;
        }
    }

    int sum = INT_MAX;

    for(int j = 0; j < n - 1; j++) {
        min_number = stoi(s.substr(j, 2));
        min_position = j;
        int sum1 = 0;

        for(int i = 0; i < n; i++) {
            if(i == min_position) {
                sum1 += min_number;
                i++; // Skip the next character as it's part of the 2-digit number
            } else {
                int x = s[i] - '0';
                if(x == 0) {
                    sum1 = 0;
                    break;
                } else {
                    if(x == 1) {
                        sum1 *= x;
                    } else {
                        sum1 += x;
                    }
                }
            }
        }
        sum = min(sum, sum1);
    }

    cout << sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
