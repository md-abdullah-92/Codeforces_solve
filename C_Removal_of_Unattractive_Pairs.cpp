#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    vector<int> v(n);
    map<char, int> mp;
    int mx=0;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        mx=max(mx,mp[s[i]]);
    }
    n=n-mx;
    int k=max((mx-n),0ll);
    if(s.size()%2&&k==0) k++;
    cout<<k<<endl;
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