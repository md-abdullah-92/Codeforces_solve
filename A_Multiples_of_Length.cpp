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
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout<<"1 1\n"<<-v[0]<<endl;
    if(n==1){
        v[0]=0;
        cout<<"1 1\n"<<v[0]<<endl;
        cout<<"1 1\n"<<v[0]<<endl;
    }
    else{
        v[0]=0;
        cout<<"1 "<<n<<endl<<v[0]<<" "; 
        for (int i = 1; i < n; i++) 
        cout<<-(n*v[i])<<" ";
        cout<<endl; 
        cout<<"2 "<<n<<endl;
        n--;
       
        for (int i = 1; i <= n; i++) 
        cout<<(n*v[i])<<" ";
        cout<<endl;
    
    }
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}