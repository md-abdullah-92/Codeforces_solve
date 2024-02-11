#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i <2*n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int sum=v[n-1]-v[0]+v[2*n-1]-v[n];
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
          cout<<v[i]<<" "<<v[i+n]<<endl;
    }
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