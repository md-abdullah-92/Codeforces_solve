#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int>ans1,ans2;
    map<int, int> mp;
    int c=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int p=-1,q=-1;
    for(int i=1;i<n;i++){
        int x=v[i]-v[i-1];
        if(x==0) c=1;
        else if(x>0)
         ans1.insert(x);
         else{
              ans2.insert(x);
         }
    }
    if(ans1.size()>1||ans2.size()>1){
        cout<<"-1\n";
        return;
    }
    if(c){
        sort(v.begin(),v.end());
        if(v[0]==v[v.size()-1]){
            cout<<0<<endl;
        }
        else{
            cout<<"-1\n";
        }
        return;
    }
    else if(ans1.size()==1&&ans2.size()==1){
        sort(v.begin(),v.end());
        int k=v[v.size()-1];
        
        int x=*ans1.begin();
        int y=*ans2.begin();
        if(k>=(x+abs(y))){
            cout<<"-1\n";
            return;
        }
        cout<<(x+abs(y))<<" "<<x<<endl;
    }
    else{
        cout<<"0\n";
    }

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