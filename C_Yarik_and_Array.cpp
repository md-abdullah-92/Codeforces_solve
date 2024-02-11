#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum=max(0ll,v[0]);
    int mx=v[0];
    for(int i=1;i<n;i++){
        if(abs(v[i]%2)==abs(v[i-1]%2)){
           sum=0;
        }
        sum=max(0ll,sum);
        sum+=v[i];
        mx=max(mx,sum);
    }
    cout<<mx<<endl;
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