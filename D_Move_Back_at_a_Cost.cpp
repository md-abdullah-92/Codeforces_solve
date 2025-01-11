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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), ans, v1(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    v1 = v;
    sort(v.begin(), v.end());

    int i = 0, j = 0;

    while (i < n) {
        if (j < n && v1[j] == v[i]) {
            // Values match, use v[i] as it is
          //  cout<<v1[j]<<" "<<j<<endl;
            ans.push_back(v1[j]);
            i++;
            j++;
        } else {
            // No match, add `v[j] + 1` and record in the map
            if(mp[v[i]] > 0) {
           // cout<<v[i]<<" "<<i<<" Handle cases where map has pending matches"<<endl;
            mp[v[i]]--;
            i++;
        }
            if(j<n&&v[i]!=v1[j]){ 
          //  cout<<v1[j]<<" "<<j<<" No match, add `v[j] + 1` and record in the map"<< endl;
            ans.push_back(v1[j] + 1);
            mp[v1[j]]++;
            j++;
            }
            // Handle cases where map has pending matches
        
        }

        
    }
    sort(ans.begin(),ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
   
    cout << endl;
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