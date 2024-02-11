#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n;
    string s;
    cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    k=3;
    for(i = 0; i < n; i++){
        cout<<k<<" ";
        k+=2;
    }
    cout<<endl;
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}