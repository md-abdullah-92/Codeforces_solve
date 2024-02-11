#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    string s, ans = "";
    vector<int> low;
    vector<int> high;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
        {
            if (high.size() > 0)
            {
                ans[high.back()] = '0'; // Change: Use back() to access the last element
                high.pop_back();
            }
        }
        else if (s[i] == 'b')
        {
            if (low.size() > 0)
            {
                ans[low.back()] = '0'; // Change: Use back() to access the last element
                low.pop_back();
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
            low.push_back(ans.size() - 1);
        }
        else
        {
            ans += s[i];
            high.push_back(ans.size() - 1);
        }
    }

    for(int i=0;i<ans.size();i++)
      if(ans[i]!='0') cout<<ans[i];
    
    cout<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
