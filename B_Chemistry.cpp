#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int> v(n);
    map<int,int>mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    int c=0,sum=0;
    for(auto k:mp){
        if(k.second%2) c++;
        sum+=k.second;
    }
    if(c>m+1){
        no;
    }
    else if(c==m||c==m+1){
        yes;
    }
    else{
        sum-=c;
        m-=c;
        if(sum>=m) {
            yes;
        }
        else no;

    }
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