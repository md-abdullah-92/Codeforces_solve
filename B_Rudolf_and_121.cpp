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
    int i=0;
    while(v[i]==0) i++;
    int j=n-1;
    while(v[j]==0) j--;
    for(;i<j-1;i++){
        if(v[i]>0){
            int k=v[i];
            v[i]-=k;
            v[i+1]-=2*k;
            v[i+2]-=k;
        }
    }
    for (int i = 0; i < n; i++) {
      //  cout<<v[i]<<" ";
        if(v[i]) {
            no;
            return;
        }
    }
    yes;
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