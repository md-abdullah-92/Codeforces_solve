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
    int n,k;
    cin >>n>>k;
    priority_queue<int>q;
    int kp=1;
    while(n){
        if(n&1) q.push(kp);
        n/=2;
        kp*=2;
    }
    if(q.size()>k){
        no;
        return;
    }
    while(q.size()!=k){
        int x=q.top();
        if(x==1){
            no;
            return;
        }
        else{
            q.pop();
            q.push(x/2);
            q.push(x/2);
        }
    }
    yes;
    while(!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}