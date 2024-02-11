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
    vector<int>first,sec;
    int sum=0,last;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        sum+=k;
        if(k>0) first.push_back(k);
        else sec.push_back(-k);
        if(i==n-1) last=k;
    }
    first.push_back(0);
    sec.push_back(0);

    if(sum>0){
        cout<<"first\n";
    }
    else if(sum<0){
        cout<<"second\n";
    }
    else{
        if(first==sec){
            if(last>0){
        cout<<"first\n";
        }
             else if(last<0){
        cout<<"second\n";
        }
        }
        for(int i=0;i<min(first.size(),sec.size());i++ ){
            if(first[i]>sec[i]) {
                cout<<"first\n";
                return;
            }
            else if(first[i]<sec[i]) 
            {cout<<"second\n";
             return;
            }
             
        }
    }
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