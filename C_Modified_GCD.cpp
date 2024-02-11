#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    int n,m;
    cin>>n>>m;
    vector<int>v;
    int q=min(n,m);
    for(int i=1;i*i<=q;i++){
        int kp=INT32_MAX;
        if(q%i==0) kp=q/i;
        if(n%i==0&&m%i==0) v.push_back(i);
        if(n%kp==0&&m%kp==0) v.push_back(kp);

    }
    sort(v.begin(),v.end());
    cin >> T;
    while (T--) {
        int x,y;
        cin>>x>>y;
        int ans=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]>=x&&v[i]<=y) ans=v[i];
        }
        cout<<ans<<endl;

    }
    return 0;
}