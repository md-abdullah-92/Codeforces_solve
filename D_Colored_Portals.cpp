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

const int INF = 1e9;
const string color[] = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve()
{
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    string s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "BG") {
            v[i] = 0;
        } else if (s == "BR") {
            v[i] = 1;
        } else if (s == "BY") {
            v[i] = 2;
        } else if (s == "GR") {
            v[i] = 3;
        } else if (s == "GY") {
            v[i] = 4;
        } else {
            v[i] = 5;
        }
    }
     vector<vector<int>> lf(n), rg(n);
        vector<int> last(6, -INF);

        // Left-to-right pass
        for (int i = 0; i < n; ++i) {
            last[v[i]] = i;   // Update last occurrence of a[i]
            lf[i] = last;     // Store the state of 'last' in 'lf'
        }

        // Reset for right-to-left pass
        last.assign(6, -INF); // Reinitialize the last array

        // Right-to-left pass
        for (int i = n - 1; i >= 0; --i) {
            last[v[i]] = i;    // Update last occurrence of a[i] (from the right side)
            rg[i] = last;      // Store the state of 'last' in 'rg'
        }
    while (k--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      int ans = INF;
      for (int j = 0; j < 6; ++j) {
        if (v[x] + j != 5 && j + v[y] != 5) {
          ans = min(ans, abs(x - lf[x][j]) + abs(lf[x][j] - y));
          ans = min(ans, abs(x - rg[x][j]) + abs(rg[x][j] - y));
        }
      }
      if (ans > INF / 2) ans = -1;
      cout << ans << '\n';
    }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}