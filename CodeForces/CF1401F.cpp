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
int n,cnt,a[1<<18];
struct lazytag
{
    int Swap,Reverse;
};
struct tree
{
    int sum,lson,rson,depth;
    lazytag lazy;
}g[1<<20];
void pushup(int now)
{
    g[now].sum=g[g[now].lson].sum+g[g[now].rson].sum;
}
void pushdown(int now)
{
    g[g[now].lson].lazy.Reverse^=g[now].lazy.Reverse;
    g[g[now].lson].lazy.Swap^=g[now].lazy.Swap;
    g[g[now].rson].lazy.Reverse^=g[now].lazy.Reverse;
    g[g[now].rson].lazy.Swap^=g[now].lazy.Swap;
    g[now].lazy.Reverse=0;
    g[now].lazy.Swap=0;
    
}
void build(int now=0,int l=1,int r=1<<n)
{
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    if(l==mid)
    {
        g[now].lson=l;
    }
    else
    {
        g[now].lson=++cnt;
        g[cnt]=(tree){-1,-1,-1,g[now].depth-1};
        build(cnt,l,mid);
    }
    if(mid+1==r)
    {
        g[now].rson=r;
    }
    else
    {
        g[now].rson=++cnt;
        g[cnt]=(tree){-1,-1,-1,g[now].depth-1};
        build(cnt,mid+1,r);
    }
    pushup(now);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    g[0]=(tree){-1,-1,-1,n};
    for(int i=1;i<=1<<n;++i)
    {
        cin>>a[i];
        g[++cnt]=(tree){a[i],-1,-1,0};
    }
    build();
    return 0;
}