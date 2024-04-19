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
    cin>>s;
    int k=1;
    int sorted=0,notsorted=0,len=0;
    for(int i=0;i<s.size();i++){
     if(s[i]=='+') len++;
     if(s[i]=='-'){
        len--;
        sorted =min(sorted,len);
        if(notsorted>len){
           notsorted=0;
        }  
     }
     if(s[i]=='1'){
        sorted=max(sorted,len);
     }
     if(s[i]=='0'){
        if (notsorted == 0 || notsorted > len)
                    notsorted = len;
        if(len<2){
         k=0;
         break;
        }
     }
     if(notsorted <= sorted && notsorted != 0) {
                k = 0;
                break;
     }
    }
    if(k){
        yes;
    }
    else no;
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