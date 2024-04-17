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
    int n,m,k,a,b;
    char s;
    cin>>n>>m>>k;
    vector<int> v;
    map<int, int> mp;
    //mp[k]++;
    set<int>st;
    st.insert(k);
    for (int i = 0;i<m; i++) {
        cin>>a>>s;
        set<int>sp;
        while(!st.empty()){
            int p=*st.begin();
            st.erase(st.begin());
            int x,y;
            x=(a+p)%n;
            if(x==0) x=n;
            if(-a+p>0) y=-a+p;
            else y=(-a+p)+n;
            if(s=='?'){
             sp.insert(x);
             sp.insert(y);
            } 
            if(s=='0') {
                sp.insert(x);
            }
            if(s=='1'){
                sp.insert(y);
            }
        }
       st=sp;
    }
    cout<<st.size()<<endl;
    for(int x:st) cout<<x<<" ";
    cout<<endl;
   // sort(v.begin(),v.end());
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