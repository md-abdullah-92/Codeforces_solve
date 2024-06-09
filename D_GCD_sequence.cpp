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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x =__gcd(v[0],v[1]);
    int k = -1;
    for (int i = 1; i < n-1; i++) {
        int p= __gcd(v[i+1],v[i]);
        if(x>p){
            k=i;
            break;
        }
        x=p;
    }
    if(k==-1){
        cout<<"YES\n";
        return;
    }
    vector<int> v1,v2,v3;
    v1=v2=v3=v;
    v1.erase(v1.begin()+k-1);
    v2.erase(v2.begin()+k);
    if(k+1<n)
    v3.erase(v3.begin()+k+1);
    x=-1,k=-1;
    for (int i = 0; i < n-2; i++) {
        int p= __gcd(v1[i+1],v1[i]);
        if(x>p){
            k=i;
            break;
        }
        x=p;
    }
    if(k==-1){
        cout<<"YES\n";
        return;
    }
    x=-1,k=-1;
    for (int i = 0; i < n-2; i++) {
        int p= __gcd(v2[i+1],v2[i]);
        if(x>p){
            k=i;
            break;
        }
        x=p;
    }
    if(k==-1){
        cout<<"YES\n";
        return;
    }
    x=-1,k=-1;
    for (int i = 0; i < n-2; i++) {
        int p= __gcd(v3[i+1],v3[i]);
        if(x>p){
            k=i;
            break;
        }
        x=p;
    }
    if(k==-1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
  
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