#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    int n, m;
    cin >> n;
    map<int, int> mp;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];
    
    cin >> m;
    vector<int> p1(m);
    for (int i = 0; i < m; i++) {
        cin >> p1[i];
        mp[p1[i]]++;
    }
    int kp=mp[p1[m-1]];

    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (v1[i] != v2[i]) {
            if(mp[v2[i]]>0) {
                mp[v2[i]]--;
            }
            else {
              //  cout<<mp[p1[m-1]]<<endl;
                cout<<"NO\n";
                return;
            }

        }
        
    }
    for (int i = 0; i < n; i++) {
        if (v1[i] == v2[i]) {
            if(mp[v1[i]]>0) {
                mp[v1[i]]--;
            }
        }
        
    }
  //  cout<<mp[p1[m-1]]<<endl;
    if(mp[p1[m-1]]==kp) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
    }
    
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
