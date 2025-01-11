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
    vector<int> v(n+1);
    vector<int> mp(n+1,1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
              if(v[i]<v[j]) mp[j]=max(mp[j],mp[i]+1);
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,mp[i]);
    cout<<mx<<endl;
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