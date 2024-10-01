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
    //an interactive problem
    int n;
    fflush(stdout);
    cin >> n;
    int k;
    map<string,int> mp;
    string s="0";
    if(n==1){
        cout<<"? 0"<<endl;
        fflush(stdout);
        cin>>k;
        if(k==0){
            cout<<"! 1"<<endl;
            fflush(stdout);
            return;
        }
        else{
            cout<<"! 0"<<endl;
            fflush(stdout);
            return;
        }
        return;
    }
    int l=1,r=1;
    while(s.size()<=n){
        if(mp[s]) k=0;
        else{
        cout<<"? "<<s<<endl;
        fflush(stdout);
        cin>>k;
        }
        if(k==1&&s.size()==n){
            cout<<"! "<<s<<endl;
            fflush(stdout);
            return;
        }
        if(l){ 
        if(k==0){
            mp[s]=1;
            char c=s[s.size()-1];
            s.pop_back();
            if(c=='0')
            s+='1';
            else    
            s+='0';
           cout<<"? "<<s<<endl;
           fflush(stdout);
           cin>>k;
           if(k==1 && s.size()==n){
               cout<<"! "<<s<<endl;
               fflush(stdout);
               return;
           }
           if(k==1){
               s+='0';
           }
           else if(k==0){
            mp[s]=1;
            s.pop_back();
            s='0'+s;
            l=0;
           }
         
        }
        else{
          if(s.size()<n)
            s+='0';
        }
        }
        else{
            if(k==0){
                mp[s]=1;
               s.erase(s.begin());
                s='1'+s;
            }
            else{
                s='0'+s;
            }
        }
    }
   
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