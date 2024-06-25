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
    int x,y,z,k;
    cin >>x>>y>>z>>k;
    map<int, int> mp;
    int maxLocations = 0;
     for (int a = 1;a <= x; ++a) {
        if (k % a == 0) {
            for (int b = 1; b<=y; ++b) {
                if ((k / a) % b == 0) {
                    int c = k / (a * b);
                    if(c<=z)
                    if (a * b * c == k) {
                         int countX = x - a + 1;
                int countY = y - b + 1;
               int countZ = z - c + 1;

               if (countX > 0 && countY > 0 && countZ > 0) {
                 int locations = countX * countY * countZ;
                   maxLocations = max(maxLocations, locations);
                   }
                    }
                }
            }
        }
    }
    cout<<maxLocations<<endl;
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