#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "Yes ";
#define no cout << "No ";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int p;
    cin >> p;
    while (p--) {
        int x;
        cin >> x;

        // Find the position of the first element greater than x
        auto it = lower_bound(v.begin(), v.end(), x);
        
        // Calculate the index (1-based) of the found element
        int index = distance(v.begin(), it) + 1;
        
    if(v[index-1]==x){
        yes;
    }
    else no;
        cout << index <<endl;
    }
    cout << endl;
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
