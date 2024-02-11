#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), ans1(n), ans2(n), mp1(n + 1), mp2(n + 1);

    queue<int> q;
    for (int &val : v) {
        cin >> val;
    }

    vector<pair<int, pair<int, int>> > p;
    int x = n - 1, y = 0, i;
    for (i = 1; i < n; i++) {
        x = min(x, i - 1);
        y = max(y, i - 1);
        if (v[i] != v[i - 1]) {
            p.push_back({v[i - 1], {x, y}});
            x = n - 1;
            y = 0;
        }
    }
    x = min(x, i - 1);
    y = max(y, i - 1);
    p.push_back({v[i - 1], {x, y}});

    sort(p.begin(), p.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    int k = 1;
    for (auto &sr : p) {
        int z = sr.first;
        x = sr.second.first;
        y = sr.second.second;
        ans1[x] = z;
        mp1[z]++;
        for (int i = x + 1; i <= y; i++) {
            while (mp1[k]) {
                k++;
            }
            ans1[i] = k;
            mp1[k]++;
        }
    }

    for (auto &sr : p) {
        int z = sr.first;
        x = sr.second.first;
        y = sr.second.second;
        ans2[x] = z;
        mp2[z]++;
        k = z - 1;
        for (int i = x + 1; i <= y; i++) {
            while (mp2[k]) {
                k--;
            }
            ans2[i] = k;
            mp2[k]++;
        }
    }

    for (int x1 : ans1) {
        cout << x1 << " ";
    }
    cout << endl;
    for (int x2 : ans2) {
        cout << x2 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
