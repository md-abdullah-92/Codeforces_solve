#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin>>n;
    vector<int>v(n),l(n,1),r(n,1);
    for(int i=0;i<n;i++){
     cin>>v[i];
    }
    int mx=1;
    for(int i=1;i<n;i++){
        if(v[i]>v[i-1]) 
            l[i]=l[i-1]+1;
    
        mx=max(mx,l[i]);
    }
    for(int i=n-2;i>=0;i--){
        if(v[i+1]>v[i]) r[i]=r[i+1]+1;
    }
    for(int i=0;i<n-2;i++){
        if(v[i]<v[i+2]) mx=max(mx,(l[i]+r[i+2]));
    }
    cout<<mx<<endl;
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}