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

constexpr int MAX_SIDE = 1000;
int tree_pref[MAX_SIDE + 1][MAX_SIDE + 1];
int forest[MAX_SIDE + 1][MAX_SIDE + 1];


void solve()
{
    int n,m;
    cin >> n>>m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            forest[i+1][j+1]+=(x=='*');
        }
    }
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] + tree_pref[i][j - 1] -
			                  tree_pref[i - 1][j - 1];
		}
	}

    for (int q = 0; q < m; q++) {
		int from_row, to_row, from_col, to_col;
		cin >> from_row >> from_col >> to_row >> to_col;
		cout << tree_pref[to_row][to_col] - tree_pref[from_row - 1][to_col] -
		            tree_pref[to_row][from_col - 1] +
		            tree_pref[from_row - 1][from_col - 1]
		     << '\n';
	}
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}