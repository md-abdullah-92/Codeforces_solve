#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "Yes\n";
#define no cout << "No\n";

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = c / a;
    int y = c / b;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if ((a * i + b * j) == c) {
                yes;
                return;
            }
        }
    }
    no;
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
