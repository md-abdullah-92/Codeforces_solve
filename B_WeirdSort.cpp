#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n, m,k;
    cin >> n >> m;
    vector<int> v1(n), srt(n + 1), str(m);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >>k;
        srt[k-1]=1;
    }
   
    vector<int> v2 = v1;
    sort(v2.begin(), v2.end());
   
    
    for (int i = 0; i < n; ++i) {
			if (srt[i] == 0) continue;
			int j = i;
			while (j < n && srt[j]) ++j;
			sort(v1.begin() + i, v1.begin() + j + 1);
			i = j;
		}
    
    if (v2 == v1) {
        yes;
    } else {
        no;
    }
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
