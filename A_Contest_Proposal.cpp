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
void shiftbyone(vector<int>& v,int temp)
{
    //int temp=v[0];
    for(int i=v.size()-1;i>0;i--)
    {   
        v[i]=v[i-1];
    }
    v[0]=temp;
}
bool checkifmatch(vector<int>& v1,vector<int>& v2)
{
    for(int i=0;i<v1.size();i++)
    {
       // cout<<v1[i]<<" ";
        if(v1[i]>v2[i])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    for(int i=0;i<n;i++)
    {
    
        if(checkifmatch(v1,v2))
        {
            cout<<i<<endl;
            return;
        }
        shiftbyone(v1,0);
       // cout<<v1[0]<<endl;

    }
    cout<<n<<endl;
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