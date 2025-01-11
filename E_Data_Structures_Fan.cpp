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
    vector<int> v(n),cul(n+1);
    string s;
    int x1=0,x0=0;
    cul[0]=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin>>s;
    for(int i = 0; i < n; i++) {
        if(s[i]=='1')  x1^=v[i];
        else x0^=v[i];
        cul[i+1]=cul[i]^v[i];
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x;
        if(x==2){
            cin>>y;
            if(y) cout<<x1<<" ";
            else cout<<x0<<" ";
        }
        else{
            cin>>x>>y;
            x--;
        int p=cul[y]^cul[x];
        x1^=p;
        x0^=p;

        }
    }
    cout<<endl;
    
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