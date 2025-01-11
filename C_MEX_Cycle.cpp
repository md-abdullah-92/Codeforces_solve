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

int find_mex(int a, int b) {
    
    // Create a set of the given two numbers
    std::unordered_set<int> numbers = {a, b};
    
    // Start checking from 0 upwards for the smallest missing number
    int mex = 0;
    while (numbers.find(mex) != numbers.end()) {
        mex++;
    }
    
    return mex;
}

void solve()
{
    int n,x,y;
    cin >> n>>x>>y;
    vector<int> v(n);
    map<int, int> mp;
    
    for (int i = 0; i <n; i++) {
        mp[(x+i)%n]=i%2;
    }
    if(n%2||(x-y)%2==0) mp[x-1]=2;
     for (int i = 0; i <n; i++) {
        cout<<mp[i]<<" ";
    }
    cout<<endl;
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