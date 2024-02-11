#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

int mp[11];
void solve()
{
    int n;
    cin >> n;
    string s="codeforces";
    if(n==1){
        cout<<s<<endl;
        return;
    }
    int k=1,cnt=2;
    for(int i=0;i<10;i++) mp[i]++;
    while(n>k){ 
    for (int i = 0; i <10; i++) {
        if(n<=k) break;
        k/=mp[i];
        k*=cnt;
        mp[i]=cnt;
    }
    if(n<=k) break;
    cnt++;
    }
    for(int i=0;i<10;i++){

        while(mp[i]){
            cout<<s[i];
            mp[i]--;
        }
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
  //  cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}