#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    int p=-1;
    for(int i=0;i<n;i++){
          if(s[i]=='0'){
            p=i;
            break;
          }
    }
    if(p==-1){
        if(n%2) n--;
            cout<<1<<" "<<(n/2)<<" "<<n/2+1<<" "<<n<<endl;
            return;
    }
    if(p<(n/2)){
        cout<<p+1<<" "<<n<<" "<<p+2<<" "<<n<<endl;
        return;
    }
    cout<<1<<" "<<p+1<<" "<<1<<" "<<p<<endl;
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