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
    int sum=0;
    for (int i = 0; i < n; i++) cin>>v[i];
    for (int i = 0; i < n; i++) {
        int mx=INT32_MIN;
        if(v[i]>0){
         while(v[i]>0&&i<n){
          mx=max(mx,v[i]);
          i++;
         }
        }
        else{
           while(v[i]<=0&&i<n){
          mx=max(mx,v[i]);
          i++;
         }  
        }
        sum+=mx;
      //  if(i==n-1) break;
        i--;
        if(i==n-1) break;
    }
    cout<<sum<<endl;
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