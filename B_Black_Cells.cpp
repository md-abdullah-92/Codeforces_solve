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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    vector<int>ans;
    if(n%2==0){ 
    for(int i=1;i<n;i+=2){
        ans.push_back(v[i]-v[i-1]);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout<<ans[0]<<endl;
    }
    else{
        if(n==1){
            cout<<"1\n";
        }
        else{
         int x = 1e18;
            for(int i = 0; i < n; i++) {
                vector<int>vv;
                for(int j = 0; j < n; j++) {
                    if(i != j)
                        vv.push_back(v[j]);
                }
 
                int pans = 1;
                for(int j = 1; j < n - 1; j += 2)
                    pans = max(pans, vv[j] - vv[j - 1]);
 
                x = min(x, pans);
            }
 
            cout << x<< "\n";
        
        }
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