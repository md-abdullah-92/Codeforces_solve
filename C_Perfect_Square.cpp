#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    string s, sr;
    cin >> n;
    vector<string> v(n), ans1(n), ans2(n);

    for (int i = 0; i < n; i++) {
        cin >> s;
        v[i] = s;
        ans1[i] = s;
        ans2[i] = s;
    }

    int sum = 0;
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int c=max({v[i][j],v[n-j-1][i],v[n-i-1][n-j-1],v[j][n-i-1]});
            sum+=(abs(v[i][j]-c)+abs(v[n-j-1][i]-c)+abs(v[n-i-1][n-j-1]-c)+abs(v[j][n-i-1]-c));

        }
    }
    
    cout << sum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
