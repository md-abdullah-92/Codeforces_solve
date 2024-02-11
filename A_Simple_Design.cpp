#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,p;
    cin >>n>>m;
    int sum=0;
    p=n;
    vector<int>v;
    while(p){
        sum+=p%10;
        v.push_back(p%10);
        p/=10;
    }

    int k=m-sum%m;
    if(k==m) cout<<n<<endl;
    else{ 
        if(k-)
    cout<<k<<endl;
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