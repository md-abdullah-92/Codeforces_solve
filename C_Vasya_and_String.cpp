#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    string s;
    cin>>n>>m>>s;
    int i=0,j=0,a=0,b=0;
    int p=0;
    while(j<n){
        while(b>m){
         a-=(s[i]=='a');
         b-=(s[i]=='b');
         i++;
        }
        a+=(s[j]=='a');
        b+=(s[j]=='b');
        if(b<=m)
        p=max((a+b),p);
        j++;
    }
    
    i=0,j=0,a=0,b=0;
    while(j<n){
        while(a>m){
         a-=(s[i]=='a');
         b-=(s[i]=='b');
         i++;
        }
        a+=(s[j]=='a');
        b+=(s[j]=='b');
        if(a<=m)
        p=max((a+b),p);
        j++;
    }
    cout<<p<<endl;
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