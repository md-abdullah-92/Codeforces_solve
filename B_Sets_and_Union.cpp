#include <bits/stdc++.h>
#define sz 4000000
#define int long long
using namespace std;
int tree[sz];
void update(int,int,int,int,int,int);
int query(int,int,int,int,int);

void update(int ind, int lb, int ub, int pos, int val,int k){
    if(lb==ub){
        if(lb == pos) {
                if(k==1) {
                    cout<<tree[ind]<<endl;
                    tree[ind]=0;
                }
            else
            tree[ind]=tree[ind]+val;
            }
        return;
    }
    int mid = ((lb+ub)>>1);
    if(pos<=mid) update((ind<<1),lb,mid,pos,val,k);
    else update((ind<<1)+1,mid+1,ub,pos,val,k);
    tree[ind] = tree[(ind<<1)] + tree[(ind<<1)+1];
}

int query(int ind, int lb, int ub, int qlb, int qub){
    if(qlb<=lb && ub<=qub) return tree[ind];
    if(qub<lb || ub<qlb) return 0;

    int p1,p2;
    int mid = ((lb+ub)>>1);
    p1= query((ind<<1),lb,mid,qlb,qub);
    p2= query((ind<<1)+1,mid+1,ub,qlb,qub);
    return p1+p2;
}
void updateValueUtil(int ss,int se,int i,
                     int diff, int si)
{
    if (i < ss || i > se)
        return;
    tree[si] = tree[si] + diff;
    if (se != ss)
    {
        int mid =(ss+se)>>1;
        updateValueUtil(ss, mid, i, diff, si>>1);
        updateValueUtil(mid+1, se, i, diff, si>>1+1);
    }
    }

int32_t main()
{
    int n, q, x, y,k,t,j;
    cin>>t;
    for(j=1;j<=t;j++){
    memset(tree,0,sizeof(tree));
    cout<<"Case "<<j<<":"<<endl;
    cin >> n>>q;
    for (int i = 1; i<=n; i++)
    {
        cin >> x;
        update(1,1,n,i,x,2);
    }
    for (int i = 0; i<q; i++)
    {
        cin >> k;
        if(k==3){
                cin>>x>>y;
                int z= query(1,1,n,x+1,y+1);
            cout <<z<< "\n";}
        else if(k==1){
                cin>>x;
            update(1,1,n,x+1,0,k);}
        else if(k==2){
            cin>>x>>y;
             update(1,1,n,x+1,y,k);
        }
    }
    }
    return 0;
}

