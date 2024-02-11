#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    string s;
    cin >> n>>s;
    vector<int> v(n);
    map<int, int> mp;
    int c=0;
    for (int i = 0; i < n-1; i++) {
        if(s[i]=='a'||s[i]=='e') {
            c++;
            cout<<s[i];
        }
        else {
            if((s[i+1]=='a'||s[i+1]=='e')&&c &&i){
                cout<<"."<<s[i];
                c=0;
            }
            else if(c&&i) {
                cout<<s[i]<<"."<<s[i+1];
                i++;
                c=0;
            }
            else cout<<s[i];
        }
        
    }
    
    cout<<s[n-1]<<endl;
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