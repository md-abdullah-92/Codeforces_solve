#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin >> n>>m;
    vector<int> v(n);
    map<int, int> mp;
    int p=0,c=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p+=(m-v[i]);
        if(m==v[i]) c=1;
    }
    sort(v.begin(),v.end());
    if(v[0]==v[n-1]&&v[0]==m){
        cout<<"0\n";
       // return;
    }
    else{
        if(p!=0&&c!=1){
            cout<<2<<endl;
        }
        else cout<<1<<endl;
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