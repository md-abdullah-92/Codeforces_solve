#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,h,w;
    cin >>n>>h>>w;
    char x,y;
    for (int i = 0; i < n; i++) {
        cin >>x>>y;
        if(w==0||x=='Y'){
            cout<<"Y ";
            w++;
            if(h>0) h--;
        }
        else  cout<<"N ";
        if(h==0||y=='Y'){
            cout<<"Y"<<endl;
            h++;
            if(w>0) w--;
        }
        else  cout<<"N"<<endl;
    }
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