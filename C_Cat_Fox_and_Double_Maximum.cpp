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
    vector<int> v(n);
    map<int, int> mp;
    int k=-1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]==n){
            k=i;
        }
    }
    vector<pair<int,int>> ans;
    vector<int>v1(n);
    int p=n;
    if(k%2==0){
        for(int i=2;i<n;i+=2){
            ans.push_back({v[i],i});
        }
        sort(ans.begin(),ans.end());   
        for(int i=0;i<ans.size();i++){
            v1[ans[i].second]=p;
            p--;
        }
        v1[0]=p;
        p--;
        ans.clear();
        for(int i=1;i<n;i+=2){
            ans.push_back({v[i],i});
        }
       // ans.clear();
        sort(ans.begin(),ans.end());     
        for(int i=0;i<ans.size();i++){
            v1[ans[i].second]=p;
            p--;
        }
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }   
        cout<<endl;

    }
    else{
         for(int i=1;i<n-1;i+=2){
            ans.push_back({v[i],i});
        }
        sort(ans.begin(),ans.end());   
        for(int i=0;i<ans.size();i++){
            v1[ans[i].second]=p;
            p--;
        }
        v1[n-1]=p;
        p--;
        ans.clear();
        for(int i=0;i<n;i+=2){
            ans.push_back({v[i],i});
        }
       // ans.clear();
        sort(ans.begin(),ans.end());     
        for(int i=0;i<ans.size();i++){
            v1[ans[i].second]=p;
            p--;
        }
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }   
        cout<<endl;

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