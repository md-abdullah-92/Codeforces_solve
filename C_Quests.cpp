#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
     vector<int> v1(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int ans=INT32_MIN;
    int mn=INT32_MIN;
    int sum=0;
    for(int i=0;i<min(n,k);i++){
        sum+=v[i];
        mn=max(mn,v1[i]);
        int sk=sum+mn*(k-i-1);
       // cout<<sk<<" ";
        ans=max(ans,sk);
    }
    cout<<ans<<endl;
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