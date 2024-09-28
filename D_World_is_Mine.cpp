#include <bits/stdc++.h>
using namespace std;
int n;
int dp[5005][5005];
map<int, int> mp;
int fun(int i,int sum){
    if(sum<0){
        return INT_MAX;
    }
    if(i==n+1){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int ans=0;
    ans=1+fun(i+1,sum+1);
    ans=min(ans,fun(i+1,sum-mp[i]));
    return dp[i][sum]=ans;

}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    } 
    cout << fun(0,0)<< endl;
    mp.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
