#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    double n,m,a,b,x,y;
    cin>>n>>m>>a>>b>>x>>y;
    double p1=sqrt(a*a+b*b),p2=sqrt(x*x+y*y);
    double q1=sqrt((a-n)*(a-n)+(b-m)*(b-m)),q2=sqrt((x-n)*(x-n)+(y-m)*(y-m));
    double sk=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    sk=sk/2;
    double ans=1e5;
    if(q1<=sk||q2<=sk){
      ans=min(ans,sk);
    }
    if(2*q1>=2*sk){
      ans=min(ans,q1);
    }
    if(2*q2>=2*sk){
      ans=min(ans,q2);
    }
    printf("%.10lf\n",ans);
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