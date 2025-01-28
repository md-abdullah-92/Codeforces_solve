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
vector<int> v;

int remaining_calls=0;

void unsort(int l,int r){
    if(r-l<=1||remaining_calls<=0){
       return;
    }
    int mid=(l+r)/2;
    if (remaining_calls > 1) {
        swap(v[mid - 1], v[mid]); // Swap two middle elements to "unsort"
        remaining_calls -= 2;
        unsort( l, mid);
        unsort( mid,r);
    }
}

void solve()
{
    int n,k;
    cin >>n>>k;
    remaining_calls=k-1;
    v.clear(); // Clear the vector to avoid issues with multiple test cases
    for (int i = 0; i < n; i++) {
        v.push_back(i+1);
    }
    if(k%2==0){
        cout<<"-1\n";
        return;
    }
    unsort(0,n);
    if(remaining_calls!=0){
        cout<<"-1\n";
        return;
    }
    for (int num : v) {
            cout << num << " ";
    }
    cout << "\n";
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
