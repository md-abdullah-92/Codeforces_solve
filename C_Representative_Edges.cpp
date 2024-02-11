#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(n<=2) {
        cout<<0<<endl;
        return;
    }
    int mn=INT32_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int c=0;
            for(int k=0;k<n;k++){
                if(i==k||j==k) continue;
                if((v[i]-v[k])*(j-i)!=(v[j]-v[i])*(i-k))
                c++;
            }
            mn=min(mn,c);
        }
    }
    cout<<mn<<endl;
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