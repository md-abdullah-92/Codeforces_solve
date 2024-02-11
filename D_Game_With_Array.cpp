#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin >> n>>m;
    if(m/2<n){
        no;
        return;
    }
    yes;
    for (int i = 0; i<n-1; i++) {
        cout<<1<<" ";
        
    }
    cout<<m-n+1<<endl;
    cout<<m/2<<endl;
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