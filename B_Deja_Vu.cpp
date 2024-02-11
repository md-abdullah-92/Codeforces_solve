#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin >>n>>m;
    vector<int> v(n);
    vector<int>x(32),ans(32);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin>>k;
        x[k]=1;
    }
    int p=1;
    for(int i=0;i<=31;i++){
          ans[i]=p;
          p*=2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=31;j++){
            if(x[j]&&<(v[i]%ans[j]==0)){
                cout<>
                v[i]+=ans[j-1];
            }
        }
    }
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout<<endl;

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