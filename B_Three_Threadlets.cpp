#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin >> n>>m>>k;
    int sum=0,sp=0;
    int p=__gcd(n,m);
    p=__gcd(p,k);
    sum=(n/p-1)+(m/p-1)+(k/p-1);
    if(sum<=3) yes;
    if(sum>3) no;

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