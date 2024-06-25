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
    string s;
    cin >> n>>s;
    int ans=n;
    for (int i = 1; i <n; i++) {
        if(n%i==0){
            string t=s.substr(0,i);
            string t2=s.substr(i,i);
          //  cout<<t<<" "<<t2<<endl;
            string temp="";
            string temp2="";
            for (int j = 0; j < n/i; j++) {
                temp+=t;
                temp2+=t2;
            }
            int c=0,cc=0;
            for(int i=0;i<n;i++){
            if(s[i]!=temp[i]) c++;
            if(s[i]!=temp2[i]) cc++;
            }
            if(c<=1||cc<=1){
                ans=i;
                break;
            }
        
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
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}