#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    m++;
    vector<int> v(n),power(10),ans;

    for (int i=0;i<n;i++) {
        cin>>v[i];
        power[v[i]]=1;
    }

    int p=1;
    for(int i=0;i<10;i++){
        if(power[i]) ans.push_back(p);
        p*=10;
    }
    int x=0,k=1;
    for(int i=1;i<ans.size();i++){
        int r=min((ans[i]/ans[i-1]-1),m);
        x+=(r*(ans[i-1]));
        m-=r;
    }
    x+=(ans.back())*m;
    
    cout<<x<<endl;
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