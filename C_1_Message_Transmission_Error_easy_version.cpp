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

//rolling hash
const int p=31;
const int m=1e9+9;
int hashf(string s){
    int hash=0;
    int p_pow=1;
    for(char c:s){
        hash=(hash+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hash;
}


void solve()
{
    string s;
    cin>>s;
    int n=s.size();
   // cout<<s;
    unordered_map<int,int>mp;
    string x="";
    for(int i=0;i<n-1;i++){
        x+=s[i];
        if(x.size()>n/2){ 
        int hash=hashf(x);
        mp[hash]++;
        }
    }
    x="";
    for(int i=n-1;i>0;i--){
        x=s[i]+x;
        if(x.size()>n/2){ 
        int hash=hashf(x);
        
        if(mp[hash]){
            yes;
            cout<<x<<endl;
            return;
        }
        }
    }
    cout<<"NO\n";
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}