#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int q;
    cin>>q;
    multiset<int>left,right;
    while(q--){
        char c;
        int m,n;
        cin>>c>>m>>n;
        if(c=='+'){
          left.insert(m);
          right.insert(n);
        }
        else if(c=='-'){
            left.erase(left.find(m));
            right.erase(right.find(n));
        }
       // cout<<*right.begin()<<" "<<*left.rbegin()<<endl;
        if(left.empty()||*right.begin()>=*left.rbegin()){
            no;
        }
        else yes;
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   /// cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}