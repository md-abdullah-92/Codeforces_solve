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
    string s;
    int c1=0,c0=0;
    cin >> n>>s;
    vector<int> v1(n+1,0),v0(n+1,0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if(s[i]=='0') {
            c0++;
        }
        else {
            c1++;
        }
        v0[i+1]=c0;
        v1[i+1]=c1;
    }
    int mn=INT32_MAX,ks=0;
    for(int i=0;i<=n;i++){
        int x=i;
        int y=(n-i);
        int x0=v0[i];
        int y0=c1-v1[i];
        int p=abs(n-2*i);
       if(2*x0>=x&&2*y0>=y){
        if(p<mn) {
            ks=i;
            mn=p;
            }
       }
    }
    cout<<ks<<endl;
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