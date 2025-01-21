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
    string s;
    cin>>s;
    int v[n][m];
    vector<int>rowsum(n,0),colsum(m,0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
           cin>>v[i][j];
           rowsum[i]+=v[i][j];
           colsum[j]+=v[i][j];
        }
    }
    int i=0,j=0;
    for(char c:s){
        if(c=='R'){
            v[i][j]=(-colsum[j]);
            rowsum[i]+=(-colsum[j]);
            colsum[j]=0;
            j++;
        }
        else{
            v[i][j]=-rowsum[i];
            colsum[j]+=-rowsum[i];
            rowsum[i]=0;
            i++;
        }
    }
    v[i][j]+=-colsum[j];
    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
           cout<<v[i][j]<<" ";
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