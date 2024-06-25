#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({1, i});
    }
    int last_turn = 1;
    while (h > 0) {
        auto [turn, i] = *s.begin();
        s.erase(s.begin());
        last_turn = turn;
        h -= a[i];
        s.insert({turn + c[i], i});
    }
    cout << last_turn << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
