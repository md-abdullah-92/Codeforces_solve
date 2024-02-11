#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin >>m>>n>>k;
    if(m>=n) {
        cout<<m<<endl;
    }
    else{
        cout<<n+(max(0ll,(n-m-k)))<<endl;
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