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
    vector<int> v(n);
    int odd=0,even=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(i%2){
            odd+=(v[i]%2);
        }
        else{
            even+=(v[i]%2);
        }
    }
    int n0=(n+1)/2;
    int n1=n/2;
    //cout<<n0<<" "<<n1<<" "<<odd<<" "<<even<<endl;
    if((n0==even||even==0)&&(n1==odd||odd==0)) {
        yes;
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