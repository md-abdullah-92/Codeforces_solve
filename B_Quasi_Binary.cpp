#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int>v,ans;
    while(n)
        {
            int k=n%10;
            v.push_back(k);
            n/=10;
        }
    int p=10;
    while(p){
        int x=0;
        for(int i=v.size()-1;i>=0;i--){
           x*=10;
           x+=(v[i]!=0);
           if(v[i]!=0) v[i]--;
        }
        if(x) ans.push_back(x);
        p--;
    }
    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";


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