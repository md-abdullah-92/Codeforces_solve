#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,m,s;
    cin>>n>>k>>m;
    int p=(n*(n+1))/2;
    int q=(k*(k+1))/2;
    s=n-k;
    int r=s*(s+1)/2;
    if(p-r>=m&&m>=q&&k<=n) yes;
    else no;

     return;
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}