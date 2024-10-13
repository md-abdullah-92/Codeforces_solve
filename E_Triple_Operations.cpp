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
vector<int>precalculation(2000005, 1);
vector<int>divisorvalue(2000005, 0);
void pre()
{
    precalculation[0] = 0;

    int k=1;
    for (int i = 1; i <= 2000005; i++) {
        if(i%3==0) k=divisorvalue[i/3]+1;
        precalculation[i]=precalculation[i-1]+k;
     //   cout<<precalculation[i]<<" "<<i<<" "<<k <<'\n';
        divisorvalue[i]=k;
        
    }
    
}

void solve()
{
    int x,y;
    cin >> x >> y;

   // cout << precalculation[y]<<" "<<precalculation[x-1] << '\n';
    cout << precalculation[y]-precalculation[x-1]+divisorvalue[x] << '\n';
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}