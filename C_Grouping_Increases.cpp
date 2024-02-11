
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
    vector<int>a1,a2;
    a1.push_back(1e10);
    a2.push_back(1e10);
    int ans=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(a1[a1.size()-1]>a2[a2.size()-1]) swap(a1[a1.size()-1],a2[a2.size()-1]);
        if(a1[a1.size()-1]>=k) a1.push_back(k);
        else if(a2[a2.size()-1]>=k) a2.push_back(k);
        else{
            a1.push_back(k);
            ans++;
        }
    }
    cout<<ans<<endl;

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