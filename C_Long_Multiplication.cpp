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
    string s1,s2;
    cin>>s1>>s2;
    int k=0;
    char x,y;
    for(int i=0;i<s1.size();i++){
        x=s1[i];
        y=s2[i];
        if(x==y) continue;
        else if(k==0){
            if(y>x){
                swap(s1[i],s2[i]);
            }
            k=1;
        }
        else{
            if(y<x){
                swap(s1[i],s2[i]);
            }
        }

    
  }
  cout<<s1<<endl<<s2<<endl;
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