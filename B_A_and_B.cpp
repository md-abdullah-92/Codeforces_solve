#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    int k=n+m;
    int p=max(m,n);
    int i=0;
    while(1){
        if(k%2==0)
        if((k)/2>=p) {
         cout<<i<<endl;
         return;
        }
        i++;
        k+=i;
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