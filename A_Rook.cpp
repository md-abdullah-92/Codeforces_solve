#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    char c;
    cin>>c>>n;
    for(int i=1;i<=8;i++)
    if(n!=i) cout<<c<<i<<endl;

    for(char p='a';p<='h';p++)
    if(c!=p) cout<<p<<n<<endl;

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