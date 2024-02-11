#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back({s.size(), s});
    }
    sort(v.begin(), v.end());
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].second.find(v[i-1].second) == string::npos) {
            c = 0;
            break;
        }
    }
    if (c){ 
        yes;
    for (auto k : v) {
        cout << k.second <<endl;
    }
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
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
