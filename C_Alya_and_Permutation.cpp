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
    int k=n;
    int p=1;
    while(k>1){
        k/=2;
        p*=2;
    }
    //cout<<p<<endl;
    if(n>4){
     if(n%2){
        cout<<n<<"\n";
        for(int i=2;i<=n-2;i++)
         cout<<i<<" ";
        cout<<"1 "<<n-1<<" "<<n<<endl;
     }
    else{
        cout<<2*p-1<<"\n";
        if(n==p){
          int sk=p/2-1;
            for(int i=2;i<=n-3;i++) 
            if(i!=p&&i!=sk&&i!=p-1) cout<<i<<" ";
            cout<<1<<" "<<sk<<" "<<p-2<<" "<<p-1<<" "<<p<<endl;
            return;
        }
        for(int i=1;i<=n;i++) 
        if(i!=p&&i!=p+1&&i!=p+2&&i!=p-1) cout<<i<<" ";
        cout<<p<<" "<<p+2<<" "<<p+1<<" "<<p-1<<endl;
        }


    }
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