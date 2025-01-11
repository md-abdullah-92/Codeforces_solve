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
    cin>>s;
    map<int, int> mp;
    int sum=0;
    for (int i = 0; i < s.size(); i++) {
        sum+=s[i]-'0';
        mp[s[i]-'0']++;
    }
    if(sum%9==0){
        yes;
        return;
    }
    for(int i=0;i<=mp[2];i++){
        for(int j=0;j<=mp[3];j++){
            int x=i*2+j*6;
            int y=sum+x;
            if(y%9==0){
                yes;
                return;
            }
        }
    }
    no;
    

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