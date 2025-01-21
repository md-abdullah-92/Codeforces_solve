#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "Yes\n";
#define no cout << "No\n";


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    map<int, int> cnt;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < n + n - m; i++) {
        if (pq.empty() || cnt[pq.top()] == 0) {
            if (pq.empty()) {
                no;
                return;
            }
            int x = pq.top();
            pq.pop();
            pq.push(x / 2);
            pq.push((x + 1) / 2);
        } else {
            cnt[pq.top()]--;
            pq.pop();
        }
    }
    if(pq.empty()){ 
    yes;
    }
    else no;
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}