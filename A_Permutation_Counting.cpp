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
    cin>>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int x=1;
    int ans=v[0];
    for(int i=1;i<n;i++)
    { 
        //cout<<v[i]<<" ";
        int p=(v[i]-v[i-1])*x;
        if(p<=k)
        {
            k-=p;
            v[i-1]=v[i];
            ans=v[i-1];
        }
        else
        {
            int q=k/x;
            v[i-1]+=q;
            ans=v[i-1];
            k-=q*x;
            break;
        }
        x++;
    }
    int q=k/x;
    ans=(ans+q)*n-(x-k%x)+1;
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