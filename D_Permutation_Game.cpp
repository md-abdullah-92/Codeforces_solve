#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> v;  // Value array
vector<int> p;  // Permutation array
int ans =0;
int mx=0;
void dfs(int t, int i, int k, vector<bool>& visited) {
    if (t == 0) {
      ans= max(k,ans);
      return;
    }
    if(v[i]==mx||visited[i]){
    int x = k + v[i] * t;
      ans= max(x,ans);
      return;
    }
    visited[i] = true;
    t--;
    int new_k = k + v[i];
    int x = k + v[i] * (t+1);
    ans= max(x, ans);
    dfs(t, p[i], new_k, visited);
    
}

void solve() {
    int n, t, pa, ps;
    cin >> n >> t >> pa >> ps;
    pa--;  // Convert to 0-based index
    ps--;  // Convert to 0-based index

    v.resize(n);
    p.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;  // Convert to 0-based index
    }
    mx=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
         mx=max(mx,v[i]);
    }
    
    // Calculate Bodya's score
    vector<bool> visited(n, false);
    ans=0;
    dfs(t, pa, 0, visited);
    int scoreBodya =ans;
   //cout<<scoreBodya<<endl;
   ans=0;
    // Calculate Sasha's score
    fill(visited.begin(), visited.end(), false);
   dfs(t, ps, 0, visited);
    int scoreSasha = ans;
   // cout<<scoreSasha<<endl;   
    if (scoreBodya > scoreSasha) {
        cout << "Bodya" << endl;
    } else if (scoreBodya < scoreSasha) {
        cout << "Sasha" << endl;
    } else {
        cout << "Draw" << endl;
    }

    v.clear();
    p.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
