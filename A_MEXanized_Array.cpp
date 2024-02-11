#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,m;
    string s;
    cin>>n>>k>>m;
    if(n<k||m+1<k) {
        cout<<"-1\n";
        return;
    }
    int p=(k*(k-1)/2);
    if(k==m) m--;
    p+=(n-k)*m;
    cout<<p<<endl;

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