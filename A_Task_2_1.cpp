#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
int lcm(int a,int b){
    return ((a/(__gcd(a,b))));
}
void solve()
{
    int l,r,n,m;
    cin>>n>>m>>l>>r;
    int x=lcm(n,m);
    r=r/x;
    r/=m;
    l=(l-1)/x;
    l/=m;
    int ans=(r-l);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}