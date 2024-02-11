#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,k;
    cin >>n>>k;
    vector<pair<int,int>> v1(n+1);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> v1[i].first;
    }
    v1[n].second=INT32_MAX;
    v1[n].first=k;
    sort(v1.begin(),v1.end());
    int sum=k;
    int p=1;
    for(auto x :v1){
        if(p==n) break;
        if(x.second<=(n-p)){
            sum+=x.first*x.second;
            p+=x.second;
        }
        else {
            sum+=(n-p)*x.first;
            p=n;
            break;
        }
    }
    cout<<sum<<endl;
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