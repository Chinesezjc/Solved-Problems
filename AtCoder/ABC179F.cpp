//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,q,a,b,ans;
struct segtree{
    int v[800005];
    #define lson (now<<1)
    #define rson (now<<1|1)
    #define lmid ((l+r)>>1)
    #define rmid (lmid+1)
    void push_down(int now)
    {
        v[lson]=min(v[now],v[lson]);
        v[rson]=min(v[now],v[rson]);
        v[now]=INF;
    }
    void change(int L,int R,int V,int now=1,int l=1,int r=n)
    {
        if(r<L||R<l)
        {
            return;
        }
        if(L<=l&&r<=R)
        {
            v[now]=min(V,v[now]);
            return;
        }
        change(L,R,V,lson,l,lmid);
        change(L,R,V,rson,rmid,r);
    }
    int query(int V,int now=1,int l=1,int r=n)
    {
        if(r<V||V<l)
        {
            return INF;
        }
        if(l==r)
        {
            return v[now];
        }
        push_down(now);
        return min(query(V,lson,l,lmid),query(V,rson,rmid,r));
    }
    void build(int now=1,int l=1,int r=n)
    {
        if(l==r)
        {
            v[now]=n;
            return;
        }
        v[now]=INF;
        build(lson,l,lmid);
        build(rson,rmid,r);
    }
}column,row;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    column.build();
    row.build();
    for(int i=1;i<=q;++i)
    {
        cin>>a>>b;
        if(a==1)
        {
            int v=column.query(b);
            if(v==1)
            {
                continue;
            }
            ans+=v-2;
            row.change(1,v,b);
            column.change(b,b,1);
        }
        if(a==2)
        {
            int v=row.query(b);
            if(v==1)
            {
                continue;
            }
            ans+=v-2;
            column.change(1,v,b);
            row.change(b,b,1);
        }
    }
    cout<<(n-2)*(n-2)-ans<<endl;
    return 0;
}