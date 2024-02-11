#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),ans;
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    int x=-1;
    for(int i=0;i<n;i++){
        if(!mp[v[i]*2]&&((v[i]%3==0&&!mp[v[i]/3])||v[i]%3)){
            x=v[i];
            break;
        }
    }
    ans.push_back(x);
    while(1){
        if(x%2==0&&mp[x/2]) {
            ans.push_back(x/2);
            x/=2;
            mp[x]--;
        }
        else if(mp[x*3]){
            ans.push_back(x*3);
            x*=3;
            mp[x]--;
        }
        else break;
    }
    reverse(ans.begin(),ans.end());
    for(int p : ans) cout<<p<<" ";
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