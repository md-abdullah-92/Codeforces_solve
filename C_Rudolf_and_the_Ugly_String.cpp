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
    cin >> n;
    cin>>s;
    int ans=0;
    int c=0;
    string sr="mapie";
    int pos = s.find(sr),total=0;
    //cout<<pos<<" ";
    while (pos < s.length()){
    pos++;
    total++;
    pos = s.find("mapie", pos);
    }
    for(int i=1;i<n-1;i++){
        string k="";
        k+=s[i-1];
        k+=s[i];
        k+=s[i+1];
        if(k=="map"||k=="pie"){
            s[i]='0';

            ans++;
        }
        
    }
  
    cout<<ans-total<<endl;
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