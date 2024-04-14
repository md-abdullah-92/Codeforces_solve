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
    string s(n, 'a');
    int pk=-1;
    for(int i=1;i<=n;i++){
        int p=(i*(i-1))/2;
        if(p>k){
          //  cout<<i<<endl;
            break;
        }
        pk=i;
    }
    int r=k-(pk*(pk-1))/2;
    
    s[n-pk-(r!=0)]='b';
   if(r) s[n-r]='b';
   else s[n-pk+1]='b';
    cout<<s<<endl;
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