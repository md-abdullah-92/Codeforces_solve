#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k>3){
        cout<<"0\n";
        return;
    }
    if(k==1){
        cout<<1<<endl;
    }
    else if(k==2){
        if(n>=m) cout<<m<<endl;
        else
        cout<<((n-1)+(m/n))<<endl;
    }
    else{
        if(m<n) cout<<0<<endl;
        else cout<<(m-n-(m/n)+1)<<endl;
    }
    
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