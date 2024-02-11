#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    if(n%3==0){
     if(n>9){
        yes;
        cout<<1<<" "<<4<<" "<<n-5<<endl;
     }
     else no;
    }
    else {
        if(n>6){
        yes;
        cout<<1<<" "<<2<<" "<<n-3<<endl;  
        }
        else no;
    }
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