#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int totalNodes = a + b + c;
    
    if (a != c - 1) {
        cout << -1 << endl;
        return;
    }
    
    // Total number of nodes to be placed
    if (totalNodes == 1) {
        cout << 0 << endl;
        return;
    }
    int height = 1,nodes=0,curr=1;
    for(int i=0;i<(a+b);i++){
        if(!curr){
            height++;
            curr=nodes;
            nodes=0;
        }
        curr--;
        nodes++;
        if(i<a) nodes++;

    }
     
    
    cout << height << endl;
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
