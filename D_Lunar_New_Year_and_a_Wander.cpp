#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> v[200005];
int vis[200005];

void bfs(int start) {
  priority_queue<int, vector<int>, greater<int> >q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int k = q.top();
        q.pop();
        cout << k << " ";

        for (int x : v[k]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(1);
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
