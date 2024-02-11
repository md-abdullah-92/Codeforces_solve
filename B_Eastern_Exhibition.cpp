#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n),v2(n);
    int x1,y1,x2,y2;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i]>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(n%2){
        cout<<1<<endl;
    }
    else{
       x1=(v1[n/2]-v1[n/2-1])+1;
       x2=(v2[n/2]-v2[n/2-1])+1;
       cout<<x1*x2<<endl;
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