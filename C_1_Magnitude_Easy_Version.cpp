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
    vector<int>ans;
    int k=v[0];
    for(int i=1;i<n;i++){
     if(v[i]>=0&&v[i-1]<0||v[i]<0&&v[i-1]>=0){
        ans.push_back(k);
       // cout<<k<<" ";
        k=v[i];
     }
     else k+=v[i];
    }
    ans.push_back(k);
    int sum1=0;
    int sum2=0;
    for(int i=0;i<ans.size();i++){
        sum2=max((sum2+ans[i]),abs(sum1+ans[i]));
        sum1+=ans[i];
    }
    sum1=abs(sum1);
    cout<<max(sum1,sum2)<<endl;
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