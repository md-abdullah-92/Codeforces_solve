#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    char c;
    map<char, int> mp;
    for (int i = 0; i <3; i++) {
        for(int j=0;j<3;j++){
            cin>>c;
            mp[c]++;
        }
    }
    if(mp['A']==2){
        cout<<'A'<<endl;
    }
    else if(mp['B']==2){
        cout<<'B'<<endl;
    }
    else if(mp['C']==2){
        cout<<'C'<<endl;
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