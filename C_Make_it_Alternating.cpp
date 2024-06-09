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

const int N=998244353;

int ncr(int n, int r){
    int ans=1;
    int k=1;
    for(int i=n;i>(n-r);i--){
        ans=(ans*i)%N;
    }
    
    return ans;
}


void solve()
{
    string s;
    cin>>s;
    int c=0;
    int k=1;
    int ans=0;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]) {
            c++;
            k++;
        }
        else {
            if(k!=1){
             ans=(ans+ncr(k,k-1))%N;
            // cout<<k<<" ";
             k=1;
            }
        }
    }
     if(k!=1)
     {
             ans+=ncr(k,k-1);
            // k=1;
           //  cout<<k<<" ";
    }
    if(ans==0) ans=1;
    cout<<c<<" "<<ans<<endl;
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