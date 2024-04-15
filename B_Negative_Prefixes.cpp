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
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int>ans;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
        if(!v2[i]){
            ans.push_back(v1[i]);
            v1[i]=0;
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    int j=0;
    for(int i=0;i<n;i++){
         if(!v2[i]){
            cout<<ans[j]<<" ";
            j++;
        }
        else{
         cout<<v1[i]<<" ";
        }
    }
    cout<<endl;
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