#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ind;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if(mp[x]==0){
            ind.push_back(x);
        }
        mp[x]++;
    }
    string c;
    cin >> c;
    sort(ind.begin(),ind.end());
    sort(c.begin(),c.end());
     for(int i=0;i<ind.size();i++){
     // cout << ind[i] << " ";
         s[ind[i]-1]=c[i];
     }
   
    
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
