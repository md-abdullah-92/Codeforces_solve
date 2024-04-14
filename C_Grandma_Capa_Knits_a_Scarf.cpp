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
    string s;
    int n;
    cin>>n>>s;
    int mn=n+1;
    for(int c=0;c<26;c++){
         int l=0,r=n-1,k=0;
         while(l<=r){ 
         if(s[l]==s[r]){
            l++;
            r--;
         }
         else{
            char x='a'+c;
            if(s[l]==x){
              //  cout<<x<<" ";
                l++;
                k++;
            }
            else if(s[r]==x){
                r--;
                k++;
            }
            else {
                k=n+1;
                break;
            }
         }
        }
         mn=min(k,mn);
    }
    if(mn==n+1) cout<<"-1\n";
    else cout<<mn<<endl;
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