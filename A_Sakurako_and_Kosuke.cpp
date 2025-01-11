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
    int a[n+1][n+1];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int ans=0;

    for(int i=0;i<n;i++) {
       for(int j=0;j<=i;j++) {
          int mn=0;
             for (int x = i - j, y = j; x < n && y < n; x++, y++) {
                    if (a[x][y] < 0) {
                        mn= min(mn, a[x][y]);
                    }
                }

              
                if (mn < 0) {
                    ans=ans+abs(mn);
                   
                    for (int x = i - j, y = j; x < n && y < n; x++, y++) {
                        a[x][y] += abs(mn);
                    }
                }

       }
    }
    cout<<ans<<endl;
   
   
    
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