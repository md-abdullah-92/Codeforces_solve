#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define sz 1e7

int32_t main()
{
    FASTIO;
    int n,m,l,r;
    //scanf("%ulld %ulld %ulld %ulld",&n,&m,&l,&r);
    cin>>n>>m>>l>>r;
    int  s = r-l+1;
    int lcm = (n/__gcd(n,m))*m;
    int x = r/lcm;
    int y = (l-1)/lcm;
    cout<<x-y<<endl;
    return 0;
}