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
    int sum=0,c=0;
    for(i = 0; i < n; i++){
        cin>>v[i];
        sum+=v[i];
    if(sum==(i+1)) c++;
    }
    cout<<c<<endl;
     return;
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