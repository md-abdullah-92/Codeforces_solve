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
    int n,m,p;
    cin >> n>>m>>p;
    set<int>v1;
    set<int>v2;
    map<int, int> mp1;
    map<int, int> mp2;
    set<int>s;
    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        if(k<=p){ 
        v1.insert(k);
        mp1[k]++;
        s.insert(k);
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin>>k;
        if(k<=p){ 
        v2.insert(k);
        mp2[k]++;
        s.insert(k);
        }
    }

    if(s.size()==p&&v1.size()>=p/2&&v2.size()>=p/2) {
    yes;
    }
    else {
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