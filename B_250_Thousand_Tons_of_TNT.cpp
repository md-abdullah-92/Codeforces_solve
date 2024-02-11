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
    set<int>ans;
    map<int, int> mp;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i=2;i*i<=n;i++){
         if(n%i==0){ 
         ans.insert(i);
         ans.insert(n/i);
         }
    }
    ans.insert(1);
    int sk=INT64_MIN;
    for(int k:ans){
        int mx=INT64_MIN,mn=INT64_MAX;
        int sum=0;
        for(int j=0;j<n;j++){
           sum+=v[j];
           if((j+1)%k==0){
           //cout<<sum<<" ";
           mx=max(mx,sum);
           mn=min(mn,sum);
           sum=0;
           }
        }
        sum=0;
       sk=max(sk,(mx-mn));
    }
    if(n==1) sk=0;
   cout<<sk<<endl;
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