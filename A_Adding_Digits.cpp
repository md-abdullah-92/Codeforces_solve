#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int p=n%m;
    p*=10;
    p=m-p%m;
    if(p==m) p=0;
    if(p>9){
        cout<<-1<<endl;
        return;
    }
    cout<<n<<p;
    for (int i = 0; i <k-1; i++) {
        cout<<0;
    }
    return;
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