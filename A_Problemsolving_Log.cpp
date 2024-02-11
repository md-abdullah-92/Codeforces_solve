#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int c=0;
    map<int, int> mp;
    for (int i = 0; i <s.size(); i++) {
        mp[(s[i]-'A'+1)]++;

    }
    for(int i=0;i<27;i++)
     if(mp[i+1]>=(i+1)) c++;
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