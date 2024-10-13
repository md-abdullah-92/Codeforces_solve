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

int n=10000000;
vector<int> v;
vector<bool> prime(n+1, true);

void sive()
{
   
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) {
            v.push_back(i);
            cout<<i<<endl;
        }
    }
    return;
}

void precaculation()
{
    
}

void solve()
{
    int n;
    cin >> n;
   //N substractions
   int i=0;
   int ans=0;
   while(v[i]<=n)
   {
    int p=n-v[i];
    if(prime[p])
    {
        ans++;
        
    }
    i++;
   }
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sive();
    int T = 1;
    cin >> T;
    int i = 1;
    while (T--) {
        cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}