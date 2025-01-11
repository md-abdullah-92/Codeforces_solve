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
    set<int>st;
    map<int,int>mp;
    vector<int>v;
    for (int i=0;i<2*n; i++) {
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]%2==0)
        st.insert(x);
    }
    if(st.size()!=n){
        no;
        return;
    }
    int sum=0;
   for(int x:st) v.push_back(x);
  // reverse(v.begin(),v.end());
    for(int i=n-1;i>=0;i--){
        v[i]-=sum;
        if(v[i]>0 and (v[i]%(2*(i+1))==0)){
            v[i]/=(2*(i+1));
            sum+=(2*(v[i]));
        }
        else{
            no;
            return;
        }
        
    }
    yes;
    
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