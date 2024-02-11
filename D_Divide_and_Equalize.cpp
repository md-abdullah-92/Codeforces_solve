#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,x;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >>x;
        for(int j=2;j*j<=x;j++){
               while(x%j==0){
                  mp[j]++;
                  x/=j;
               }
        }
        if(x>1) mp[x]++;
    }
    for(auto xp:mp){
        if(xp.second%n!=0){
            no;
            return;
        }
    }
    yes;
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