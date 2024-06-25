#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll log_2(ll n) {
    if(n==0) {
        return -1; 
    }
    ll pos=0;
    ll bitPos=-1;
    while(n>0) {
        if(n&1) {
            bitPos=pos;
        }
        n=n>>1;
        pos++;
    }
    return bitPos;
}
ll MEX(vector<ll> &a) {
    std::unordered_set<ll> s(a.begin(), a.end());
    ll mex=0;
    while(s.find(mex)!=s.end()) {
        mex++;
    }
    return mex;
}
int binarySearch(vector<ll> &arr, int l, int r, int x) {
    while(l<=r) {
        int m=l+((r-l)/2);
        if(arr[m]==x) {
            return m;
        }
        if(arr[m]<x) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    return -1;
}
int countSubstring(string &s1, string &s2) {
	if(s2.length()==0) {
        return 0;
    }
	int ct=0;
	for(size_t offset=s1.find(s2); offset!=std::string::npos; offset=s1.find(s2, offset+s2.length())) {
		++ct;
	}
	return ct;
}
bool isSubSequence(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}
// bool ok(vector<int> &a, int target, int k) {
//     int n=a.size();
//     int curr_or=0;
//     int hsh[20]={0};
//     for(int i=0; i<k; i++) {
//         for(int j=0; j<20; j++) {
//             if(a[i]&(1<<j)) {
//                 hsh[j]++;
//             }
//         }
//         curr_or|=a[i];
//     }
//     if(curr_or!=target) {
//         return false;
//     }
//     for(int i=k; i<n; i++) {
//         for(int j=0; j<20; j++) {
//             if(a[i-k]&(1<<j)) {
//                 hsh[j]--;
//                 if(hsh[j]==0) {
//                     curr_or&=~(1<<j);
//                 }
//             }
//         }
//         for(int j=0; j<20; j++) {
//             if(a[i]&(1<<j)) {
//                 hsh[j]++;
//             }
//         }
//         curr_or|=a[i];
//         if(curr_or!=target) {
//             return false;
//         }
//     }
//     return true;
// }
bool ok(vector<int> &a) {
    int n=a.size();
    int ct=0;
    for(int i=0; i<n; i++) {
        if(a[i]>a[(i+1)%n]) {
            ct++;
        }
    }
    return ct<=1;
}
ll GCD(vector<ll> &a) {
    int n=a.size();
    ll gcd=0; 
    for(int i=0; i<n; i++) { 
        gcd=__gcd(gcd, a[i]); 
    } 
    return gcd; 
}
ll LCM(vector<ll> a) {
    ll lcm=a[0];
    for(int i=1; i<a.size(); i++) {
        ll num1=lcm;
        ll num2=a[i];
        ll gcd=__gcd(num1, num2);
        lcm=(lcm*a[i])/gcd;
    }
    return lcm;
}
ll lcm(ll a, ll b) {
    return (a/__gcd(a, b))*b;
}
bool isSorted(vector<ll> a, int size) {
    for(int i=1; i<size; i++) {
        if(a[i-1]>a[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        // string s;
        // cin>>s;
        // string decoy=s;
        // sort(decoy.begin(), decoy.end());
        // int n=s.length();
        // if(decoy[0]==decoy[n-1]) {
        //     cout<<"NO"<<endl;
        // } else {
        //     cout<<"YES"<<endl;
        //     int pos=0;
        //     for(int i=0; i<n; i++) {
        //         if(s[i]!=s[pos]) {
        //             swap(s[i], s[pos]);
        //             break;
        //         }
        //     }
        //     cout<<s<<endl;
        // }
        // int n;
        // cin>>n;
        // vector<ll> k(n, 0);
        // for(int i=0; i<n; i++) {
        //     cin>>k[i];
        // }
        // ll lcm=LCM(k);
        // vector<ll> ans{};
        // ll sum=0;
        // for(int i=0; i<n; i++) {
        //     ans.push_back(lcm/k[i]);
        //     sum+=ans[i];
        // }
        // if(sum>=lcm) {
        //     cout<<-1<<endl;
        // } else {
        //     for(int i=0; i<n; i++) {
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // ll n, k, g;
        // cin>>n>>k>>g;
        // ll stolen=min(n*((g-1)/2), k*g);
        // ll rem=((k*g)-stolen)%g;
        // if(rem>0) {
        //     stolen-=((g-1)/2);
        //     ll last=(((g-1)/2)+rem)%g;
        //     if(2*last<g) {
        //         stolen+=last;
        //     } else {
        //         stolen-=(g-last);
        //     }
        // }
        // cout<<stolen<<endl;
        // int n;
        // cin>>n;
        // vector<ll> a(n);
        // for(int i=0; i<n; i++) {
        //     cin>>a[i];
        // }
        // sort(a.begin(), a.end());
        // ll ans=0;
        // for(int i=0; i<n; i++) {
        //     if(a[i]<0) {
        //         ans=a[i];
        //         break;
        //     }
        // }
        // if(ans<0) {
        //     cout<<ans<<endl;
        // } else {
        //     cout<<a[n-1]<<endl;
        // }
        // int n;
        // cin>>n;
        // vector<int> p(n+1, 0);
        // for(int i=1; i<=n; i++) {
        //     cin>>p[i];
        // }
        // int pos_n=-1, pos1=-1, pos2=-1;
        // for(int i=1; i<=n; i++) {
        //     if(p[i]==1) {
        //         pos1=i;
        //     }
        //     if(p[i]==2) {
        //         pos2=i;
        //     }
        //     if(p[i]==n) {
        //         pos_n=i;
        //     }
        // }
        // if(pos_n<pos1 && pos_n<pos2) {
        //     cout<<pos_n<<" "<<min(pos1, pos2)<<endl;
        // } else if(pos_n>pos1 && pos_n>pos2) {
        //     cout<<pos_n<<" "<<max(pos1, pos2)<<endl;
        // } else {
        //     cout<<pos1<<" "<<pos2<<endl;
        // }
        // int n, m;
        // cin>>n>>m;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(i%2) {
        //             cout<<((i/2)*m)+j+1<<" ";
        //         } else {
        //             cout<<(((n/2)+(i/2))*m)+j+1<<" ";
        //         }
        //     }
        //     cout<<endl;
        // }
        // int n, m;
		// cin>>n>>m;
		// vector<char> a(n+1), b(m+1);
		// for(int i=1; i<=n; i++) {
		// 	cin>>a[i];
		// }
		// for(int i=1; i<=m; i++) {
		// 	cin>>b[i];
		// }
		// vector<int> dp(m+1);
		// dp[1]=(a[1]==b[1] ? 1 : 0);
		// for(int i=2; i<=m; i++) {
		// 	if(dp[i-1]!=n && b[i]==a[dp[i-1]+1]) {
		// 		dp[i]=dp[i-1]+1;
		// 	} else {
		// 		dp[i]=dp[i-1];
		// 	}
		// }
		// cout<<dp[m]<<endl;
        // int n;
        // cin>>n;
        // vector<ll> a(n);
        // ll mini=INT_MAX;
        // for(int i=0; i<n; i++) {
        //     cin>>a[i];
        //     mini=min(mini, a[i]);
        // }
        // bool b=true;
        // for(int i=0; i<n-1; i++) {
        //     if((a[i]%2)!=(a[i+1]%2)) {
        //         b=false;
        //         break;
        //     }
        // }
        // if(b) {
        //     cout<<"yes"<<endl;
        // } else {
        //     if(mini%2) {
        //         cout<<"yes"<<endl;
        //     } else {
        //         cout<<"no"<<endl;
        //     }
        // }
        // int n;
        // cin>>n;
        // vector<int> m(n);
        // vector<string> s(n);
        // for(int i=0; i<n; i++) {
        //     cin>>m[i]>>s[i];
        // }
        // bool b1=false, b2=false, b3=false;
        // int ans1=INT_MAX, ans2=INT_MAX, ans3=INT_MAX;
        // for(int i=0; i<n; i++) {
        //     if(s[i]=="10") {
        //         ans1=min(ans1, m[i]);
        //         b1=true;
        //     }
        //     if(s[i]=="01") {
        //         ans2=min(ans2, m[i]);
        //         b2=true;
        //     }
        //     if(s[i]=="11") {
        //         ans3=min(ans3, m[i]);
        //         b3=true;
        //     }
        // }
        // if(b1 && b2 && b3) {
        //     cout<<min(ans1+ans2, ans3)<<endl;
        // } else if(!b1 && b2 && b3) {
        //     cout<<ans3<<endl;
        // } else if(b1 && !b2 && b3) {
        //     cout<<ans3<<endl;
        // } else if(b1 && b2 && !b3) {
        //     cout<<ans1+ans2<<endl;
        // } else if(b1 && !b2 && !b3) {
        //     cout<<-1<<endl;
        // } else if(!b1 && b2 && !b3) {
        //     cout<<-1<<endl;
        // } else if(!b1 && !b2 && b3) {
        //     cout<<ans3<<endl;
        // } else {
        //     cout<<-1<<endl;
        // }
        // int n, k;
        // cin>>n>>k;
        // int pos=-1;
        // for(int i=0; i<n; i++) {
        //     if((i*(i-1)/2)+((n-i)*(n-i-1)/2)==k) {
        //         pos=i;
        //     }
        // }
        // if(pos==-1) {
        //     cout<<"no"<<endl;
        // } else {
        //     cout<<"yes"<<endl;
        //     for(int i=0; i<n; i++) {
        //         if(i<pos) {
        //             cout<<1<<" ";
        //         } else {
        //             cout<<-1<<" ";
        //         }
        //     }
        //     cout<<endl;
        // }
        // string s;
        // cin>>s;
        // int n=s.length();
        // int ans=1;
        // if(s[0]=='0') {
        //     ans=0;
        // }
        // if(s[0]=='?') {
        //     ans=9;
        // }
        // for(int i=1; i<n; i++) {
        //     if(s[i]=='?') {
        //         ans*=10;
        //     }
        // }
        // cout<<ans<<endl;
        // string s;
        // cin>>s;
        // int n=s.length();
        // if(s=="^") {
        //     cout<<1<<endl;
        // } else {
        //     int ans=0;
        //     if(s[0]=='_') {
        //         ans++;
        //     }
        //     if(s[n-1]=='_') {
        //         ans++;
        //     }
        //     for(int i=0; i<n-1; i++) {
        //         if(s[i]=='_' && s[i+1]=='_') {
        //             ans++;
        //         }
        //     }
        //     cout<<ans<<endl;
        // }
        // int n, k;
        // cin>>n>>k;
        // vector<string> t(n);
        // int ans=n;
        // for(int i=0; i<n; i++) {
        //     cin>>t[i];
        //     if(t[i]!=t[0]) {
        //         ans--;
        //     }
        // }
        // cout<<ans<<endl;
        // int n;
        // cin>>n;
        // vector<ll> a(n+1, 0);
        // for(int i=1; i<=n; i++) {
        //     cin>>a[i];
        // }
        // bool b=false;
        // for(int i=1; i<=n; i++) {
        //     if(a[i]<=i) {
        //         b=true;
        //         break;
        //     }
        // }
        // if(b) {
        //     cout<<"yes"<<endl;
        // } else {
        //     cout<<"no"<<endl;
        // }
        // int n;
        // cin>>n;
        // vector<ll> a(n);
        // for(int i=0; i<n; i++) {
        //     cin>>a[i];
        // }
        // if(a[0]==a[n-1]) {
        //     cout<<"no"<<endl;
        // } else {
        //     string s="";
        //     s+='B';
        //     if(a[n-1]-a[1]==0) {
        //         s+='B';
        //         for(int i=0; i<n-2; i++) {
        //             s+='R';
        //         }
        //     } else {
        //         for(int i=0; i<n-1; i++) {
        //             s+='R';
        //         }
        //     }
        //     cout<<"yes"<<endl;
        //     cout<<s<<endl;
        // }
        ll x;
        cin>>x;
        string s=to_string(x);
        ll n=s.length();
        if(s[n-1]=='9') {
            cout<<"no"<<endl;
        } else {
            bool ans=true;
            for(int i=n-1; i>=1; i--) {
                if(s[i]>='0' && s[i]<='8') {
                    s[i]='0';
                    if(s[i-1]=='0') {
                        ans=false;
                        break;
                    } else {
                        s[i-1]--;
                    }
                } else {
                    ans=false;
                    break;
                }
            }
            if(ans) {
                if(s[0]=='0' && s[1]=='0') {
                    cout<<"yes"<<endl;
                } else {
                    cout<<"no"<<endl;
                }
            } else {
                cout<<"no"<<endl;
            }
        }
    }
}