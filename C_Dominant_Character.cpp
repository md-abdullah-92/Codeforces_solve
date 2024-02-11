#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";


void solve() {
    int n;
    string s;
    cin>>n>>s;
    int ans=n+5;
    for(int i=0;i<n-1;i++)
    {
        vector<int>mp(3,0);
        mp[s[i]-'a']++;
        for(int j=i+1;j<min(n,i+7);j++){
            mp[s[j]-'a']++;
            if(mp[0]>mp[1]&&mp[0]>mp[2]){
                ans=min(ans,(j-i+1));
            }

        }
    }
    if(ans>=(n+5)) ans=-1;
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
