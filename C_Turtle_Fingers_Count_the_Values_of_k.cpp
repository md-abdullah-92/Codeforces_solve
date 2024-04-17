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
    int n,m,l;
    cin >> n>>m>>l;
    vector<int> v(n);
    map<int, int> mp;
    int k=1,r=1;
    int sum=0;
    int c=0;
   /* if(n==m){
        int pk=1;
        while(l%n==0){
            l/=n;
            pk++;
        }
       cout<<pk<<endl;
       return;
    }*/
    set<int>st;
    for (int i = 0; i<34; i++) {
        r=1;
        for(int j=0;j<34;j++){
            int p=k*r;
            if(p>l){
                c=1;
                break;
            }
           if(l%p==0)  st.insert(l/p);
         r*=m;
        }
        if(k>l)break;
        k*=n;

    }
    
    cout<<st.size()<<endl;
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