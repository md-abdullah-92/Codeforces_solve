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
    int n,m,k;
    cin >>n>>m>>k;
    vector<int> v1(n);
    vector<int> v2(m);
    vector<int>ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if((v1[i]+v2[j])<=k) sum++;
          else break;
        }
    }
    cout<<sum<<endl;
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