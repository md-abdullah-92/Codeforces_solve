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
    int n,m;
    cin >> n>>m;
    vector<int> v(n),p(m),new1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(v.begin(),v.end());
    sort(p.begin(),p.end());
    int sum=0,k=0;
    for(int i=0;i<m;i++){
        if(p[i]==1){
             sum+=2*(v[v.size()-1]);
             v.pop_back();
        }
        else if(p[i]==2){
             sum+=(v[v.size()-1]+v[v.size()-2]);
             v.pop_back();
             v.pop_back();
        }
        else{
            sum+=v[v.size()-1];
            v.pop_back();
            new1.push_back(p[i]-1);
        }
    }
    if(new1.size()){ 
    sort(new1.begin(),new1.end(),greater<int>());
    for(int j=0;j<new1.size();j++) {
        //cout<<v[k]<<" ";
        sum+=v[k];
        k+=new1[j];
    }
    }
    cout<<sum<<endl;
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