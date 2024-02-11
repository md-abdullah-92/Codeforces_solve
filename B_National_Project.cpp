#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(m>=k) {
        cout<<n<<endl;
        return;
    }
    else {
            int p=n/2+(n%2);
            int ans;
            int x=p/m;
            if(p%m) ans=x*(m+k)+max(p%m,(n-x*(m+k)));
            else ans=(x-1)*(m+k)+max(m,(n-(x-1)*(m+k)));
            cout<<ans<<endl;
        
    }
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