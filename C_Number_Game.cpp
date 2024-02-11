#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,p=0;
    multiset<int>s,c;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k;
        c.insert(k);
    }
    for(int k=1;k<=n;k++){
        s=c;
        for(int i=0;i<k;i++){
        auto it=s.upper_bound(k - i);
        if (it==s.begin()) break;
        s.erase(--it);
        if (!s.empty()) {
          int x=*s.begin();
          s.erase(s.begin());
          s.insert(x+k-i);
        }
        }
        if (s.size() + k == n) {
            p=k;
        }
    }
    cout<<p<<endl;
    return;
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}