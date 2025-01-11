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
vector<int>v(3e5+10,0);
void func(){
   int n=3e5;
   v[0]=0;
   for(int i=1;i<n;i++) v[i]=v[i-1]^i;
}

void solve()
{
    int n,k;
    cin >>n>>k;
    int xr=v[n-1];
    if((xr^k)==0){
        cout<<n<<endl;
    }
    else if((xr^k)==n){
        cout<<n+2<<endl;
    }
    else{
        cout<<n+1<<endl;
    }
   
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    func();
    while (T--) {
        solve();
    }
    return 0;
}