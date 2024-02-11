#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,x,y,p,q;
    cin>>n>>m>>x>>y;
    p=(x-n);
    q=(y-m);
    if(q<0||p>q){
        cout<<"-1\n";
        return;
    }
    p=q-p;
         cout<<p+abs(q)<<endl;
    
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