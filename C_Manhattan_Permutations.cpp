#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,k;
    cin >> n>>k;
    int maxi=n*(n-1);
    if(k%2||maxi<k){
        no;
        return;
    }
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        v[i]=i+1;
    }
    int j=n-1;
    int i=0;
    while(k>0&&i<j){
        if(k>=(j-i)*2){
            swap(v[i],v[j]);
            k-=(j-i)*2;
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    if(!k){
        yes;
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    else{
        no;
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