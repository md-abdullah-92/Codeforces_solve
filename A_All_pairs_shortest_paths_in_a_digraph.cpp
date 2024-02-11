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

void solve()
{
    int n;
    cin >> n;
   int v[n+1][n+1];  
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){ 
               cin >> v[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the above source
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
            
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                
            }
        }
    }
     for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){ 
               cout << v[i][j]<<" ";
        }
        cout<<endl;
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