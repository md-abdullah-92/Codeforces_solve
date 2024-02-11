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
    vector<int> v(n);
    map<int, int> mp,mp1;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum+=v[i];
        mp[v[i]]++;
    }
    if(sum&1) {
        no;
        return;
    }
    else {
    sum/=2;
    int presum=0,reqsum;
    for(int i=0;i<n;i++){
        presum+=v[i];
        mp1[v[i]]++;
        mp[v[i]]--;
        reqsum=(sum-presum);
        if(reqsum==0||mp[reqsum]||mp1[-reqsum]){
            yes;
            return;
        }
    }
    no;

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