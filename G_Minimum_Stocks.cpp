#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

bool compare(pair<string ,int> i,pair<string, int> j) {
  return i.second < j.second;
}

void solve()
{
    int n,k,v;
    string s;
    map<string,int>mp;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>k>>s;
        if(k==1){
            cin>>v;
            mp[s]=v;
        }
        else if(k==2){
            cin>>v;
            mp[s]=v;
        }
        else {
            pair<string,int>p;
            p=*min_element(mp.begin(),mp.end(), compare);
            cout<<p.first<<" "<<i+1<<endl;
            mp.erase(p.first);
        }
    }
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