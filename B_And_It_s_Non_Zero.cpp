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
 vector<vector<int>> mp(200001,vector<int>(19,0));
void solve()
{
    
  // vector<vector<int>> mp(200001,vector<int>(19,0));
    for(int i=1;i<=200000;i++){
        for(int j=0;j<=18;j++){
            int k=(i>>j)&1;
            mp[i][j]=mp[i-1][j]+(k!=0);
        }
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        int mx=0;
        for(int i=0;i<=18;i++){
            int c=mp[m][i]-mp[n-1][i];
            mx=max(c,mx);
        }
        int p=(m-n)+1;
        cout<<p-mx<<endl;
    }
    
    return 0;
}