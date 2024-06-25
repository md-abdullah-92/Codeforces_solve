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
    string s="##";
    string s1="..",ans0="",ans1="";
    cin >> n;
    int c=1;
    for(int i=0;i<n;i++){
       if(c){
        ans0+=s;
        ans1+=s1;
       }
       else{
        ans0+=s1;
        ans1+=s;
       }
       c^=1;
    }
    for(int i=0;i<n;i++){
        if(i%2) {
            cout<<ans1<<endl<<ans1;
        }
        else {
            cout<<ans0<<endl<<ans0;
        }
        
        
        cout<<endl;
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