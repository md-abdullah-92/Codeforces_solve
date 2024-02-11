#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    
    int i,j,k,n;
    cin>>n;
    while(n--){ 
    string s,sp1="abc",sp2="acb",sp3="bac",sp4="cba";
    cin>>s;
    if(s==sp1||s==sp3||s==sp4||s==sp2) yes;
    else no;
    }
     return;
    
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--)
        solve();
    return 0;
}