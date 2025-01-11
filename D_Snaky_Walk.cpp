#include <bits/stdc++.h>
using namespace std;

int vertical_dx[] = {1, -1}; 
int vertical_dy[] = {0, 0};
int horizontal_dx[] = {0, 0};
int horizontal_dy[] = {1, -1}; 

int vis[1000][1000][2];
int h, w;
vector<string> grid;
int start_x, start_y, goal_x, goal_y;

bool valid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#';
}
int bfs(int start_x, int start_y, int goal_x, int goal_y) {
    queue<tuple<int, int, int, int>> q; 
    q.push({start_x, start_y, 0, 0}); 
    q.push({start_x, start_y, 1, 0}); 
    vis[start_x][start_y][0] = 1;
    vis[start_x][start_y][1] = 1;

    while (!q.empty()) {
        auto [x, y, direction, steps] = q.front();
        q.pop();

        if (x == goal_x && y == goal_y) {
            return steps;
        }

        
        if (direction == 0) { 
            for (int i = 0; i < 2; i++) {
                int nx = x + horizontal_dx[i];
                int ny = y + horizontal_dy[i];
                if (valid(nx, ny) && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = 1;
                    q.push({nx, ny, 1, steps + 1}); 
                }
            }
        } else { 
            for (int i = 0; i < 2; i++) {
                int nx = x + vertical_dx[i];
                int ny = y + vertical_dy[i];
                if (valid(nx, ny) && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = 1;
                    q.push({nx, ny, 0, steps + 1});
                }
            }
        }
    }

    return -1; 
}

int main() {
    cin >> h >> w;
    grid.resize(h);

    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 'G') {
                goal_x = i;
                goal_y = j;
            }
        }
    }

    memset(vis, 0, sizeof(vis));

    int result = bfs(start_x, start_y, goal_x, goal_y);
    cout << result << endl;

    return 0;
}
