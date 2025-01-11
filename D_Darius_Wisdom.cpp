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
    vector<int> v(n),v2(n);
    set<int>zero,one,two;
    map<int, int> mp;
    vector<pair<int,int>>ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]==0) zero.insert(i);
        else if(v[i]==1) one.insert(i);
        else two.insert(i);
    }
    v2=v;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i]==0){
            if(v[i]!=v2[i]){
                int k=*zero.rbegin();
                if(v2[i]==1){
                   ans.push_back({k+1,i+1});
                
                zero.erase(k);
                swap(v2[i],v2[k]);
                one.insert(k);
                one.erase(i);
                }
                else{
                    int p=*one.rbegin();
                      ans.push_back({p+1,i+1});
                      ans.push_back({k+1,i+1});
                      one.insert(k);
                      two.insert(p);
                      zero.erase(k);
                      one.erase(p);
                      two.erase(i);
                     v2[i]=0;
                     v2[k]=1;
                     v2[p]=2;
                }
            }

        }
    }
    for(int i=0;i<n;i++){
        if(v[i]==1){
            if(v[i]!=v2[i]){
                int k=*one.rbegin();
                ans.push_back({k+1,i+1});  
                one.erase(k);

                v2[i]=1;
                v2[k]=2;
                two.insert(k);
                two.erase(i);
            }

        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
   // cout<<endl;

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