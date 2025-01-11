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

pair<int,int> function1(int l,int r,int k){
   if (r-l + 1 < k) {
        return {0, 0};
    }
 
 
    if (r-l+ 1 == 1) {
        return {l, 1};
    }
    int mid = l + (r - l) / 2;
 
    if ((r+1-l) % 2) { 
 
        pair<int, int> lr = function1(l, mid - 1, k);
        int t= mid + 2 * lr.first + mid * lr.second;
        int ts = 2 * lr.second + 1;
 
        return {t, ts};
    } else { 
 
         pair<int, int> lr  =  function1(l, mid, k);;
 
 
         int t=2 * lr.first + mid * lr.second;
        int ts = 2 * lr.second;
 
        return {t, ts};
    }
 
    
}

void solve()
{
    int n,k;
    cin >> n>>k;
    pair<int,int>p;
    p=function1(1,n,k);
    cout<<p.first<<endl;
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