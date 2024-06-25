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
    string s;
    cin >> s;
    int b=0,r=0;
    int ans=1;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            b++;
        }
        else if(s[i]=='R'){
            r++;
        }
        else {
            if((b==0&&r==0)||(b&&r)) {
                b=0;
                r=0;
            }
            else{
            ans=0;
            break;
            }
        }

    }
      if((b==0&&r==0)||(b&&r)) {
                b=0;
                r=0;
            }
            else{
            ans=0;
            
            }
    if(ans){
        yes;
    }
    else{
        no;
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