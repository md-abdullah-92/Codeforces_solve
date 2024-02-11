#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),ans(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ans=v;
    sort(ans.begin(),ans.end());
    int i=0;
    while(v[i]==ans[i]&&i<n) i++;
    if(i==n) {
        cout<<"0\n";
        return;
    }
    int j=v.size()-1;
     while(v[j]==ans[j]) j--;
    for(int k=i;k<=j;k++){
        if(v[k]==ans[k]) {
            cout<<2<<endl;
            return;
        }
    }
    cout<<1<<endl;
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