#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int unsigned long long
int lcm(int x,int i){
    return (x*i)/(__gcd(x,i));
}

void solve()
{
    int n;
    cin >> n;
    int x=1;
    int ans=n;
    for (int i =1;i<=n; i++) {
        x=lcm(x,i);
        if(x>n){
            cout<<ans<<endl;
            return;
        }
        ans+=n/x;
        ans%=mod;
    }
    cout<<ans<<endl;
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