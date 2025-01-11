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
    int n,k;
    cin >> n>>k;
    vector<int>ans;
    string s;
    cin>>s;
    int sum=0;
    for (int i = n-1; i >0; i--) {
        if(s[i]=='1') sum++;
        else sum--;
        if(sum>0) ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    int ans1 = 1;
    while (k > 0 && !ans.empty()) {
      k -= ans.back();
      ans.pop_back();
      ++ans1;
    }
    cout << (k > 0 ? -1 : ans1) << '\n';
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