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
    map<string, string> mp;
    map<string,int>x;
    vector<pair<string,string>>v;
    string a,b;
    for (int i = 0; i < n-1; i++) {
       cin>>a>>b;
       v.push_back({a,b});
       mp[a]=b;
       x[b]++;
    }
    string s;
    for(auto y:v){
        string k=y.first;
        if(!x[k]){
           s=k;
        }
    }
    cout<<s<<endl;

    while(n>=1){
        cout<<mp[s]<<endl;
        s=mp[s];
        n--;
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int i=1;i<=T;i++) {
        cout<<"Scenario #"<<i<<":"<<endl;
        solve();
    }
    return 0;
}