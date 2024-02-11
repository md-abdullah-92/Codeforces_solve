#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    string s1,s2;
    cin>>n>>m;
    cin>>s1>>s2;
    vector<int>v1,v2;
    int k=0;
    for(int i=0;i<s1.size();i++){
          if(k==s2.size()) break;
          if(s1[i]==s2[k]) {
            v1.push_back(i);
            k++;
          }
    }
    k=s2.size()-1;
     for(int i=s1.size()-1;i>=0;i--){
          if(k==-1) break;
          if(s1[i]==s2[k]) {
            v2.push_back(i);
            k--;
          }
    }
    reverse(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<v1.size()-1;i++){
       // cout<<v1[i]<<" "<<v2[i]<<endl;
        ans=max((v2[i+1]-v1[i]),ans);
    }
    cout<<ans<<endl;
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}