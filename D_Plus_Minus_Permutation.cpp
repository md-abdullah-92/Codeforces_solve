#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,m;
    string s;
    cin>>n>>m>>k;
    int p=(n/m);
    int r=m*k/(__gcd(m,k));
    p=p-n/r;
    p=n-p;
    int q=n/k-n/(r);
    p=(n*(n+1))/2-((p)*(p+1))/2;
    q=(q*(q+1))/2;
    cout<<p-q<<endl;
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