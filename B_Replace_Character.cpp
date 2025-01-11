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
    cin>>s;
    map<char,int>mp;
    int mn=n+1;
    int mx=0;
    char x=s[0],y=s[0];
    for (int i = 0; i < n; i++) {
       mp[s[i]]++;
    }
    for (int i = 0; i < n; i++) {

       if(mn>mp[s[i]]){
        mn=mp[s[i]];
        x=s[i];
       }  
        if(mx<mp[s[i]]){
        mx=mp[s[i]];
        y=s[i];
       }    
    }
   // cout<<x<<" "<<y<<endl;
    for(int i=0;i<n;i++){
        if(x==y){
        if(s[i]!=y){
           s[i]=y;
           break;
        }
        }
        else if(s[i]==x){
            s[i]=y;
            break;
        }
    }
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