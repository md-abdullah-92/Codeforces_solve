#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

int h,c,t;

double f1(int x)
{
    double th = x * (h + c);
 
    th /= (2 * x);
 
    return abs(th - t);
}
double f2(int x)
{
    double th = x * h + (x - 1) * c;
 
    th /= (2 * x) - 1;
 
    return abs(th - t);
}
 
int ternary1(int l, int r)
{
    while ( l < r - 2)
    {
        int mid1 = (l * 2 + r) / 3;
        int mid2 = (l + r * 2) / 3;
 
        if (f1(mid1) <= f1(mid2)) r = mid2;
        else
            l = mid1;
    }
 
    double val = 1e9;
 
    int idx = l;
 
    for (int i = l; i <= r; i++)
    {
        if (val >f1(i))
        {
            idx = i;
            val = f1(i);
        }
    }
 
    return idx;
 
 
}
int ternary2(int l, int r)
{
    while ( l < r - 2)
    {
        int mid1 = (l * 2 + r) / 3;
        int mid2 = (l + r * 2) / 3;
 
        if (f2(mid1) <= f2(mid2)) r = mid2;
        else
            l = mid1;
    }
 
    double val = 1e9;
 
    int idx = l;
 
    for (int i = l; i <= r; i++)
    {
        if (val > f2(i))
        {
            idx = i;
            val = f2(i);
        }
    }
 
    return idx;
}

void solve()
{
    cin>>h>>c>>t;
    int cnt1 = ternary1(1, 1e12);
    int cnt2 = ternary2(1, 1e12);
    if (f1(cnt1) < f2(cnt2))
    {
        cout << cnt1 * 2 << endl;
    }
    else
    {
        cout << cnt2 * 2 - 1 << endl;
    }

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