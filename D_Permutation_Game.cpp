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
    int n,k,pa,pb;
    cin >>n>>k>>pa>>pb;
    vector<int> v1(n),p1(n);
    for(int i=0;i<n;i++) cin>>p1[i];
    for(int i=0;i<n;i++) cin>>v1[i];
    map<int, int> mp;
    int i=k;
    int suma=0,sumb=0;
    while(--i){
        suma+=v1[pa-1];
        int p=p1[pa-1];
     if(v1[pa-1]<=v1[p]){
        pa=p;
     }
     else{
        suma+=v1[pa-1]*i;
        i=0;
     }
    }
    i=k;
    while(--i){
        sumb+=v1[pb-1];
        int p=p1[pb-1];
     if(v1[pb-1]<=v1[p]){
        pb=p;
     }
     else{
        sumb+=v1[pb-1]*i;
        i=0;
     }
    }
    cout<<suma<<" "<<sumb<<endl;
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