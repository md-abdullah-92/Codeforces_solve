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
    char c;
    cin>>c;
    string s;
    cin>>s;
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c) k++;
    }
    if(k==n){
        cout<<0<<endl;
        return;
    }
    if(s[n-1]==c){
        cout<<1<<endl<<n<<endl;
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int flag=1;
        if(s[i-1]!=c) continue;
        for(int j=i;j<=n;j+=i){
         if(s[j-1]!=c) {
            flag=0;
            break;
         }
        }
        if(flag){
            cout<<1<<endl<<i<<endl;
            return;
        }
    }
    
        cout<<2<<endl<<n-1<<" "<<n<<endl;
    
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