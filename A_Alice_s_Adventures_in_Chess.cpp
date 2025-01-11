#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,x,y;
    int a=0,b=0;
    string s,p;
    cin>>n>>x>>y;
    cin>>s;
    p=s;
    for(int i=0;i<100;i++) s+=p;
    
    for (int i = 0; i <s.size(); i++) {
        if(s[i]=='N') b++;
        if(s[i]=='E') a++;
        if(s[i]=='S') b--;
        if(s[i]=='W') a--;
     //   cout<<a<<" "<<b<<endl;
        if(a==x&&b==y){
            yes;
            return;
        }
    } 
    no;
    
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