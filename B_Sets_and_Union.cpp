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



void solve() {
    int n;
    cin >> n;
    vector<set<int>> v(n);
    set<int> s;
    map<int, set<int>> mp;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
            s.insert(x);
            mp[x].insert(i);
            cnt[x]++;   
        }
    }

    int ans = 0;
    for(int i=1;i<=50;i++){
        set<int> temp;
        map<int, int> mp1;
        mp1=cnt;
        temp=mp[i];
        int cnt1=0;
        for(int k:temp){
           for(int j:v[k]){
                if(mp1[j]==1){
                     cnt1++;
                }
               mp1[j]--;
           }
        }
        if(cnt1==0){
            continue;
        }
        cnt1=s.size()-cnt1;
        ans=max(ans,cnt1);
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
