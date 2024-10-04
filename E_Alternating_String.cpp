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

int arr[2][30];

void solve()
{
    int n;
    cin >> n;
    map<int,map<char, int>>mpa,mpb;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
            mpa[i%2][s[i]]++;
        }
    if(s.size()%2){
        int pos=-1,ans=0;
        for(int j=0;j<n;j++){ 
            int odd=0,even=0;                      
            for(char i='a';i<='z';i++){
            int oddx=mpb[1][i]+(mpa[0][i]-mpb[0][i]);
            int evenx=mpb[0][i]+(mpa[1][i]-mpb[1][i]);
            if(s[j]==i){
                if(j%2==0){
                    oddx--;
                }
                else{
                    evenx--;
                }
            }
            odd=max(odd,oddx);
            even=max(even,evenx);
            }
            if(ans<(odd+even)){
                ans=odd+even;
                pos=j;
            }
            mpb[j%2][s[j]]++;
        } 
        cout<<n-ans<<endl; 
        return;
    }
    int ans=0;
    int odd=0,even=0;   
    for(char i='a';i<='z';i++){
        odd=max(odd,mpa[0][i]);
        even=max(even,mpa[1][i]);
    }
    cout<<n-odd-even<<endl;
   
    
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