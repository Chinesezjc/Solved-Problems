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
int n,m,r,p,a,b,c,d,cnt;
struct node{
    int p,v,depth,top,fa,size;
    vector<int> son;
}g[100005];
struct tree{
    int sum,lson,rson,l,r,lazytag;
}h[200005];
bool cmp(const int &A,const int &B)
{
    return g[A].size>g[B].size;
}
void init1(int now)
{
    g[now].size=1;
    for(int i=0;i<(int)g[now].son.size();++i)
    {
        if(g[now].fa==g[now].son[i])
        {
            swap(g[now].son[i],g[now].son.back());
            g[now].son.pop_back();
            --i;
            continue;
        }
        g[g[now].son[i]].depth=g[now].depth+1;
        g[g[now].son[i]].fa=now;
        init1(g[now].son[i]);
        g[now].size+=g[g[now].son[i]].size;
    }
    sort(g[now].son.begin(),g[now].son.end(),cmp);
}
void init2(int now)
{
    g[now].p=++cnt;
    h[g[now].p]=(tree){g[now].v%p,-1,-1,g[now].p,g[now].p};
    if(g[now].son.size())
    {
        g[g[now].son[0]].top=g[now].top;
        init2(g[now].son[0]);
    }
    for(int i=1;i<(int)g[now].son.size();++i)
    {
        g[g[now].son[i]].top=g[now].son[i];
        init2(g[now].son[i]);
    }
}
void push_down(int now)
{
    (h[h[now].lson].lazytag+=h[now].lazytag)%=p;
    (h[h[now].rson].lazytag+=h[now].lazytag)%=p;
    (h[h[now].lson].sum+=h[now].lazytag*(h[h[now].lson].r-h[h[now].lson].l+1))%=p;
    (h[h[now].rson].sum+=h[now].lazytag*(h[h[now].rson].r-h[h[now].rson].l+1))%=p;
    h[now].lazytag=0;
}
void push_up(int now)
{
    h[now].sum=(h[h[now].lson].sum+h[h[now].rson].sum)%p;
}
void build(int now)
{
    if(h[now].l==h[now].r)
    {
        return;
    }
    int mid=(h[now].l+h[now].r)>>1;
    if(h[now].l==mid)
    {
        h[now].lson=mid;
    }
    else
    {
        h[++cnt]=(tree){0,-1,-1,h[now].l,mid};
        h[now].lson=cnt;
        build(cnt);
    }
    if(h[now].r==mid+1)
    {
        h[now].rson=mid+1;
    }
    else
    {
        h[++cnt]=(tree){0,-1,-1,mid+1,h[now].r};
        h[now].rson=cnt;
        build(cnt);
    }
    push_up(now);
}
void add(int L,int R,int v,int now=n+1)
{
    if(now==-1||h[now].r<L||R<h[now].l)
    {
        return;
    }
    if(h[now].l==h[now].r)
    {
        (h[now].sum+=v)%=p;
        return;
    }
    if(L<=h[now].l&&h[now].r<=R)
    {
        (h[now].lazytag+=v)%=p;
        (h[now].sum+=v*(h[now].r-h[now].l+1))%=p;
        return;
    }
    push_down(now);
    add(L,R,v,h[now].lson);
    add(L,R,v,h[now].rson);
    push_up(now);
}
int ask(int L,int R,int now=n+1)
{
    if(now==-1||h[now].r<L||R<h[now].l)
    {
        return 0;
    }
    if(h[now].l==h[now].r)
    {
        return h[now].sum;
    }
    if(L<=h[now].l&&h[now].r<=R)
    {
        return h[now].sum;
    }
    push_down(now);
    return (ask(L,R,h[now].lson)+ask(L,R,h[now].rson))%p;
}
void work1(int f,int t,int v)
{
    while(g[f].top!=g[t].top)
    {
        if(g[g[f].top].depth<g[g[t].top].depth)
        {
            add(g[g[t].top].p,g[t].p,v);
            t=g[g[t].top].fa;
        }
        else
        {
            add(g[g[f].top].p,g[f].p,v);
            f=g[g[f].top].fa;
        }
    }
    if(g[f].depth<g[t].depth)
    {
        add(g[f].p,g[t].p,v);
    }
    else
    {
        add(g[t].p,g[f].p,v);
    }
}
int work2(int f,int t)
{
    int tmp=0;
    while(g[f].top!=g[t].top)
    {
        if(g[g[f].top].depth<g[g[t].top].depth)
        {
            (tmp+=ask(g[g[t].top].p,g[t].p))%=p;
            t=g[g[t].top].fa;
        }
        else
        {
            (tmp+=ask(g[g[f].top].p,g[f].p))%=p;
            f=g[g[f].top].fa;
        }
    }
    if(g[f].depth<g[t].depth)
    {
        (tmp+=ask(g[f].p,g[t].p))%=p;
    }
    else
    {
        (tmp+=ask(g[t].p,g[f].p))%=p;
    }
    return tmp;
}
void work3(int now,int v)
{
    add(g[now].p,g[now].p+g[now].size-1,v);
}
int work4(int now)
{
    return ask(g[now].p,g[now].p+g[now].size-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;++i)
    {
        cin>>g[i].v;
    }
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        g[a].son.push_back(b);
        g[b].son.push_back(a);
    }
    init1(r);
    g[r].top=r;
    init2(r);
    h[++cnt]=(tree){0,-1,-1,1,n};
    build(cnt);
    for(int i=1;i<=m;++i)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c>>d;
            work1(b,c,d);
        }
        if(a==2)
        {
            cin>>b>>c;
            cout<<work2(b,c)<<endl;
        }
        if(a==3)
        {
            cin>>b>>c;
            work3(b,c);
        }
        if(a==4)
        {
            cin>>b;
            cout<<work4(b)<<endl;
        }
    }
    return 0;
}