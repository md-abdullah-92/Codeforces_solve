#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char str[200000];
    string a1="(",a2="{",a3="[",a4="<",a5="(*";
    while (gets(str)) {
        vector<int>v;
        stack<char>s;
        int n=strlen(str);
        int i=0;
        int wr=0;
        while(i!=n){
        if(str[i]=='('||str[i]=='{'||str[i]=='['||str[i]=='{'||str[i]=='<'||(str[i-1]=='(')&&str[i]=='*'){ 
        s.push(str[i]);
        if(str[i]!='*') {
            wr++;
        }
        }
        else if((str[i]==')'||str[i]=='}'||str[i]==']'||str[i]=='>'||(str[i]=='*'&&str[i+1]==')'))){
                if(s.empty() &&str[i]=='*'){
                    wr++;
                    break;
                }
                else if(s.empty() &&(str[i]==')'||str[i]=='}'||str[i]==']'||str[i]=='>'))
                {
                    wr++;
                    break;
                }
                else if(s.top()=='*'&&str[i]=='*' )
                {
                    s.pop();
                    s.pop();
                    wr++;
                    i++;
                }
                else if(!s.empty() &&((s.top()=='('&&str[i]==')')||(s.top()=='{'&&str[i]=='}')||(s.top()=='['&&str[i]==']')||(s.top()=='<'&&str[i]=='>')))
                {
                    s.pop();
                    wr++;
                }
                else
                {
                    wr++;
                    break;
                }
        }
        else wr++;
        i++;
        }
        if(s.empty() &&n==i)
            printf("YES\n");
        else if(!s.empty() &&n==i)
            printf("NO %ld\n",++wr);
        else
            printf("NO %ld\n",wr);
    }
    return 0;
}