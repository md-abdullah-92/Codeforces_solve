#include<bits/stdc++.h>
using namespace std;

#define x 10005
#define inf 1e18

vector<pair<int, int>> adj[x];
int v[x];

void bfs(int st, int n, int d) {
    for (int i = 1; i <= n; i++) {
        v[i] = inf;
    }

    priority_queue<pair<int, int>> pq;
    v[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = -pq.top().first;

        if (u == d) return;

        pq.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int vx = adj[u][i].first;
            int len = adj[u][i].second;

            if (cost + len <v[vx]) {
                vx[v] = cost + len;
                pq.push({-v[vx], vx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    string cityName;

    cin >> t;

    for (int n = 1; n <= t; n++) {
        int numNodes;
        cin >> numNodes;

        unordered_map<string, int> nodeMapping;

        for (int i = 1; i <= numNodes; i++) {
            cin >> cityName;
            nodeMapping[cityName] = i;

            int neighbors, neighborNode, cost;
            cin >> neighbors;

            for (int j = 1; j <= neighbors; j++) {
                cin >> neighborNode >> cost;
                adj[i].push_back(make_pair(neighborNode, cost));
            }
        }

        int numRoutes, startNode, endNode;
        cin >> numRoutes;

        for (int i = 1; i <= numRoutes; i++) {
            cin >> cityName;
            startNode = nodeMapping[cityName];

            cin >> cityName;
            endNode = nodeMapping[cityName];

            bfs(startNode, numNodes, endNode);
            cout << v[endNode] << endl;
        }

        for (int i = 1; i <= numNodes; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
