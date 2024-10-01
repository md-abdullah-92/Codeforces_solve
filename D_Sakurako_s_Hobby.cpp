#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<int> parent(200005), sz(200005); 
int make (int v) {
    parent[v] = v;

}
int find_set(int v) {
    if (v == parent[v]) { 
        return v;
    }
    return parent[v] = find_set(parent[v]); 
}

 void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n;
    cin >> n;   
    vector<int> v(n);
    string s;
    for (int i = 0; i < n; i++) {
        make(i+1);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    

    }
    cin >> s;
   for(int i=0;i<n;i++){
   if(s[i]=='0'){
       sz[i + 1]=1;
       }
       else{
        sz[i+1]=0;
       }
    }
    for(int i=0;i<n;i++){
        union_sets(i+1,v[i]);
    }
    for(int i=0;i<n;i++){
        cout<<sz[find_set(i+1)]<<" ";
    }

    cout<<endl;
    


   
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}
