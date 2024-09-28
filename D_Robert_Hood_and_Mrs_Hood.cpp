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
    int n,d,k;
    cin>>n>>d>>k;
    map<int, int> start, end; //

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        start[x]++;
        end[y]++;
    }
    for(int i=1;i<=n;i++){
        start[i]+=start[i-1];
        end[i]+=end[i-1];
    }
      int best_start = 0, worst_start = 0;
      int max = 0, min = INT32_MAX;
    for(int i=d;i<=n;i++){
        int cur=start[i]-end[i-d];
      //  cout<<cur<<" ";
        if(cur>max){
            max=cur;
            best_start=i-d+1;
        }
        if(cur<min){
            min=cur;
            worst_start=i-d+1;
        }
    }
    cout<<best_start<<" "<<worst_start<<endl;
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
