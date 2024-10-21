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
    string s1,s2;
    cin >> s1>>s2;
    int n=s1.size(),m=s2.size();
    int k=0;
    int i=0;
    int j=0;
    while(n>i&&m>j&&s1[i]==s2[j])
    {
        i++;
        j++;
    }
    if(i==0) {
        cout<<n+m<<endl;
        return;
    }
    int ans=n+m-i+1;
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