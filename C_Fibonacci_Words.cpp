#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
   string s;
   cin>>s;
   int c=1;
   for(int i=1;i<s.size()-1;i++){
    char p=(s[i]-'A'+s[i-1]-'A')%26+'A';
    if(p!=s[i+1]){
        c=0;
        break;
    }

   }
   if(c) {
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