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
int a,b;
int dif(int x,int y){
    return ((x-a)*(x-a)+(y-b)*(y-b));
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    int x,y;
    cin>>x>>y>>a>>b;
    int p=dif(x,y);
     for (int i = 0; i < n; i++) {
        int xp=dif(v[i].first,v[i].second);
        if(xp<=p){
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