#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    string s1,s2;
    cin >> n>>m>>s1>>s2;
    vector<int> v(n);
    int p=(25/min(s2.size(),s1.size()));
    map<int, int> mp;
    for (int i = 0; i <6; i++) {
        if(s1.find(s2)!=-1){
            cout<<i<<endl;
            return;
        }
        s1+=s1;
    }
     cout<<"-1"<<endl;
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