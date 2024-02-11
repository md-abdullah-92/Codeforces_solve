#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),c(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int>s;
    for(int i=n-1;i>=0;i--){
      s.insert(v[i]);
      c[i]=s.size();
    }
    s.clear();
    int ans=0;
    for(int i=0;i<n;i++){
          if(s.find(v[i])==s.end()){
            ans+=c[i];
            s.insert(v[i]);
          }
    }
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}