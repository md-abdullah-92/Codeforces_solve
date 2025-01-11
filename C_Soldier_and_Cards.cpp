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
    int n;
    cin >> n;
    deque<int> v1,v2;
    int x,y;
    cin>>x;
    while(x--){
        int k;
        cin>>k;
        v1.push_back(k);
    }
    cin>>y;
    while(y--){
        int k;
        cin>>k;
        v2.push_back(k);
    }
    int i=0;
     if(v1.empty()){
            cout<<i<<" "<<2<<endl;
            return;
        }
        if(v2.empty()){
            cout<<i<<" "<<1<<endl;
            return;
        }
    while(!v1.empty()&&!v2.empty()&&i<=1000){
         i++;
         x=v1.front();
         y=v2.front();
         v1.pop_front();
         v2.pop_front();
         if(x>y){
            v1.push_back(y);
            v1.push_back(x);
         }
         if(x<y){
            v2.push_back(x);
            v2.push_back(y);
         }

        if(v1.empty()){
            cout<<i<<" "<<2<<endl;
            return;
        }
        if(v2.empty()){
            cout<<i<<" "<<1<<endl;
            return;
        }
    }
    cout<<"-1\n";
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
  //  cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}