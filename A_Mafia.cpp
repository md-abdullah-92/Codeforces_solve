#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";


void solve()
{
    int n;
    cin >> n;
    int sum=0;
    int mx=INT32_MIN;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        mx=max(mx,x);
        sum+=x;
    }
    sum+=n-2;
    mx=max(mx,sum/(n-1));
    cout<<mx<<endl;
    return;
}

int32_t main()
{
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}