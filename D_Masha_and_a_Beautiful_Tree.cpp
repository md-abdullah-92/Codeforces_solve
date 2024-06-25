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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l=n;
    int k=0;
    vector<int> v1;
    v1=v;
    k=1;
    int ans=0;
    while(n>1){
        vector<int> v2;
        int p=0;
        while(p<l-1){
          //  cout<<p<<" "<<p+k<<endl;
           if(abs(v1[p]-v1[p+k])==k){

              if(v1[p]>v1[p+k]){
                  ans++;
                  swap(v1[p],v1[p+k]);
              }
           }
           else{
               cout<<-1<<endl;
               return;
           }
           p+=(k*2);
        }
        n/=2;
        k*=2;
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