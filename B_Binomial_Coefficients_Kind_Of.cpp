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
vector<int> fact(1000005,1);
void precalce()
{   
    int k=1;
    for(int i=0;i<1000005;i++)
    {
        fact[i]=k;
        k=(2*k)%1000000007;
    }
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==r[i])
        {
            cout<<1<<endl;
            return;
        }
        cout<<fact[r[i]]<<endl;
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    precalce();
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}