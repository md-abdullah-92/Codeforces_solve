#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<pair<pair<int, int>, int>> ans;
    map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    
    int start = 0;
    int currentSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        currentSum += v[i].second;
        
        if (v[i].first % v[i + 1].first != 0) {
            ans.push_back({{start, i}, currentSum});
            start = i + 1;
            currentSum = 0;
        }
    }
    
    currentSum += v[n - 1].second;
    ans.push_back({{start, n - 1}, currentSum});
    
    int maxLength = 0;
    
    for (auto p : ans) {
      //  cout<<i<<" "<<j<<" "<<sum<<endl<<endl;
        int i = p.first.first;
        int j = p.first.second;
        int sum = p.second;
        cout<<i<<" "<<j<<" "<<sum<<endl<<endl;
        while (i <= j) {
            if (sum <= k) {
                maxLength = max(maxLength, j - i + 1);
                break;
            }
            
            if (v[i].second > v[j].second) {
                sum -= v[i].second;
                i++;
            } else {
                sum -= v[j].second;
                j--;
            }
        }
    }
    
    cout << maxLength << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}
