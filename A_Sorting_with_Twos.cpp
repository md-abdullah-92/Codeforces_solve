#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),ans(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int p=1;
    while(p<=n-1){
        ans[p-1]=1;
        p*=2;
    }
    int c=1;
    for(int i=0;i<n-1;i++){
        if(ans[i]) continue;
        if(v[i]>v[i+1]) {
            c=0;
        }
    }
 //   for(int k:v) cout<<k<<" ";
  //  sort(v.begin(),v.end());
    if(c) {
        yes;
    }
    else no;
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