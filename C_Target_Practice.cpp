#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n;
    vector<string>v;
    char c;
    cin>>n;
    while(n--){ 
    int ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>c;
            int x=min(i+1,(10-i));
            int y=min(j+1,(10-j));
        
            if(c=='X') {
                ans+=(min(x,y));
              //  cout<<min(x,y)<<" ";
            }
        }
    }
    cout<<ans<<endl;
    }
    return;
}
     
int32_t main()
{
    int T = 1;
   // cin >> T;
    while (T--)
        solve();
    return 0;
}