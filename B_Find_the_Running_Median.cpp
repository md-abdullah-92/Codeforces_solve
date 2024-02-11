#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n, k;
    cin >> n;
    priority_queue<int> mx;  // max heap
    priority_queue<int, vector<int>, greater<int>> mn;  // min heap
    cin >> k;
    mx.push(k);
    double ans = k;
    printf("%.1lf\n", ans);
    for (int i = 1; i < n; i++)
    {
        cin >> k;
        if (mx.size() > mn.size())
        {
            if (k < mx.top())
            {
                mn.push(mx.top());
                mx.pop();
                mx.push(k);
            }
            else
                mn.push(k);
            ans = (mx.top() + mn.top()) / 2.0;
        }
        else
        {
            if (k > mx.top())
            {
                mn.push(k);
                mx.push(mn.top());
                mn.pop();
            }
            else
                mx.push(k);
            ans = mx.top();
        }
        printf("%.1lf\n", ans);
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
