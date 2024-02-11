#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n, k;
    string s1 = "add", s;
    stack<int> v;
    cin >> n;
    int t =1, c = 0;

    for (int i = 0; i < 2 * n; i++) {
        cin >> s;
        if (s == s1) {
            cin >> k;
            v.push(k);
        } else {
           if(!v.empty()){
                if(v.top()==t){
                    v.pop();
                }else{ 
                    c++;
                    while(!v.empty()) v.pop();
                }
            }
            t++;
        }
    }
    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
