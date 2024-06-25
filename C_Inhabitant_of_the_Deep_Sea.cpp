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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int x = k / 2 + k % 2;
    int y = k / 2;
    int i = 0, j = n - 1;
    int ans = 0;
    if(n==1){
        if(k>=v[0]){
            cout<<1<<endl;
            return;
        }
    }
    while (i <= j) {
        
        if (v[i] <= x) {
            x -= v[i];
            ans++;
            i++;
        }
        if (v[j] <= y) {
            y -= v[j];
            ans++;
            j--;
        }
        if (i == j) {
            x += y;
            y = 0;
            if (v[i] <= x) {
                x -= v[i];
                ans++;
            }
            break;
        } else if (v[j] > y && v[i] > x||i>j) {
            break;
        }
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
