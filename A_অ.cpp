#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>


void solve()
{
    int n;
    string s;
    cin >>s>>n;

    //vector<int> v(n);
   /// map<int, int> mp;
    for (int i = 0; i < n; i++) {
        next_permutation(s.begin(),s.end());
    }
    cout<<s<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}