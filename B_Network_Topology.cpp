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
    int n,m;
    cin >> n>>m;
    map<int, int> mp;
    for (int i = 0; i <m; i++) {
        int x,y;
        cin>>x>>y;
        mp[x]++;
        mp[y]++;
    }
    int x1=0,x2=0,x3=0,xn=0;
    for(int i=1;i<=n;i++){
        if(mp[i]==1) x1++;
        if(mp[i]==3) x3++;
        if(mp[i]==2) x2++;
        if(mp[i]==n-1) xn++;
    }
   // cout<<x1<<" "<<x2<<" "<<x3<<" "<<xn<<endl;
    if(x1==n-1&&xn==1){
        cout<<"star topology\n";
        return;
    }
    else if(x2==n-2&&x1==2){
        cout<<"bus topology\n";
        return;
    }
    else if(x2==n){
        cout<<"ring topology\n";
        return;
    }
    else{
        cout<<"unknown topology\n";
        return;
    }
  

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
  //  cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}