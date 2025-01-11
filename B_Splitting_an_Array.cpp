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

bool isvalid(vector<int> &a, int k, int mid){
      int groups = 0, sum = 0;
             int n = a.size();
             for(int i=0;i<n;i++){
                 if(a[i] > mid)return false;
 
                 if(sum + a[i] > mid){
                     groups++;
                     sum=0;
                 }
                 sum += a[i];
             }
 
             if(sum > 0)groups++;
 
             return groups <= k;
}

void solve()
{
    int n,k;
    cin >>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum+=v[i];
    }
    int l=0,h=sum,ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(isvalid(v,k,mid)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
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
 //   cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}