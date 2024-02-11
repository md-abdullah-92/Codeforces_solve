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
    cin>>v[0];
    cout<<v[0]<<" ";
    int sum=v[0];
    int s=sum%2;
    for (int i =1; i < n; i++) {
        cin >> v[i];
        sum+=v[i];
        s+=v[i]%2;
        if(s%3==1) {
            cout<<sum-(s/3+1)<<" ";
        }
        else{
            cout<<sum-(s/3)<<" ";
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