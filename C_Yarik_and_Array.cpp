#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mx=INT32_MIN;
    int sum=0;
    int k=-1;
    for(int i=0;i<n;i++) {
       int z = abs(v[i])%2;
       if(z==k){
        sum=0;
       }
       if(sum<0) {
           sum=0;
         }
         sum+=v[i];
         k=z;
         mx=max(mx,sum);
       
    }
    cout<<mx<<endl;
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