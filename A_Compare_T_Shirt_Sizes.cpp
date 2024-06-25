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
    string s1,s2;
    cin>>s1>>s2;
    
    if(s1==s2){
        cout<<"=\n";
    }
    else if(s1[s1.size()-1]==s2[s2.size()-1]){
        if(s1.size()>s2.size()&&s1[s1.size()-1]=='S'){
            cout<<"<\n";
        }
        else if(s1.size()>s2.size()&&s1[s1.size()-1]=='M'){
            cout<<"<\n";
        }
        else if(s1.size()>s2.size()&&s1[s1.size()-1]=='L'){
            cout<<">\n";
        }
        else if(s1.size()<s2.size()&&s1[s1.size()-1]=='S'){
            cout<<">\n";
        }
        else if(s1.size()<s2.size()&&s1[s1.size()-1]=='M'){
            cout<<">\n";
        }
        else if(s1.size()<s2.size()&&s1[s1.size()-1]=='L'){
            cout<<"<\n";
        }
    }
    else{
        if(s1[s1.size()-1]=='S'){
            cout<<"<\n";
        }
        else if(s1[s1.size()-1]=='M'&&s2[s2.size()-1]=='S'){
            cout<<">\n";
        }
        else if(s1[s1.size()-1]=='M'&&s2[s2.size()-1]=='L'){
            cout<<"<\n";
        }
        else if(s1[s1.size()-1]=='L'){
            cout<<">\n";
        }
        else{
            cout<<"<\n";
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