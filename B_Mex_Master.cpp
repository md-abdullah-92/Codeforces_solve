#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    int c=0,d=0;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
      if(v[i]==0) c++;
      if(v[i]==1) d++;
    }
    if(c<=(n+1)/2) cout<<0<<endl;
    else if((c)==n||(c+d)!=n) cout<<1<<endl;
    else cout<<2<<endl;

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