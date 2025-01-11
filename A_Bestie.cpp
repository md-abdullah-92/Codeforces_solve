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
    int mx=0;
    int g=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        g=__gcd(v[i],g);
      
    }
    if(g==1){
        cout<<"0\n";
        return;
    }
    vector<int>gd;
    for(int i=max(n-3,0ll);i<n;i++){
        g=0;
        for(int j=0;j<n;j++){
            int x=v[j];
            if(i==j){
                x=__gcd(x,j+1);
              //  cout<<x<<endl;
                gd.push_back(x);
            }
            g=__gcd(g,x);
        }
        if(g==1) mx=i;
    }
    int ans=min(n-mx,3ll);



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