#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    string s;
    cin >>n>>s;
    
    set<char>st;
    for (int i = 0; i < n; i++) {
        st.insert(toupper(s[i]));
    }
    if(st.size()==26) {
        yes;
    }
    else no;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}