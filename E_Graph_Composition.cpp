#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int,int>>a,b;

    DSU dsuF(n), dsuG(n);

    // Read edges of F
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back({u,v});
    }

    // Read edges of G
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        b.push_back({u,v});
        dsuG.unite(u,v);
    }

    int ans=0;

    for(auto &[u, v] : a) {
        if(dsuG.find(u) == dsuG.find(v)) {
            dsuF.unite(u, v);
        } else {
            ans += 1;
        }
    }
    for(auto &[u, v] : b) {
        if(dsuF.find(u) != dsuF.find(v)) {
            dsuF.unite(u, v);
            ans += 1;
        }
    }
 
    cout << ans<< '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
