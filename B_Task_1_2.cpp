#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,s;
    cin>>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    for(i = 0; i < n; i++){
        cin>>v[i];
    }
    int sum=0;
    
    while(k--){
    cin>>s;
    sum+=v[s-1];
    }
    cout<<sum<<endl;
    
    return;
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}