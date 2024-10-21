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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    int left = 0, ans = 0, cnt = 0, distinct = 0;

    for (int right = 0; right < n; right++) {
        if (mp[v[right]] == 0) {
            distinct++;
        }
       
        mp[v[right]]++;
        cnt++;

        while (distinct > k) {
            mp[v[left]]--;
            if (mp[v[left]] == 0) {
                distinct--;
            }
            cnt--;
            left++;
        }
        ans = max(ans, cnt);
         if(v[right+1] - v[right]>1) {
            left = right+1;
            cnt = 0;
            distinct = 0;
            mp.clear();
            continue;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
