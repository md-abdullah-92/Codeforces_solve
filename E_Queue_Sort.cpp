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
    int p=INT32_MAX,c=-1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(p>v[i]) {
            c=i;
            p=v[i];
        }
    }
    
    for(int i=c+1;i<n;i++){
        if(v[i-1]>v[i]) c=-1;
    }
    cout<<c<<endl;
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