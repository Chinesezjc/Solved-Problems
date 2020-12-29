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
int n,m,r,a,b,fa[500005],top[500005],depth[500005],size[500005];
vector<int> son[500005];
bool cmp(const int &A,const int &B)
{
    return size[A]>size[B];
}
void init1(int now)
{
    size[now]=1;
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(son[now][i]==fa[now])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]]=now;
        depth[son[now][i]]=depth[now]+1;
        init1(son[now][i]);
        size[now]+=size[son[now][i]];
    }
    sort(son[now].begin(),son[now].end(),cmp);
}
void init2(int now)
{
    if(son[now].size())
    {
        top[son[now][0]]=top[now];
        init2(son[now][0]);
    }
    for(int i=1;i<(int)son[now].size();++i)
    {
        top[son[now][i]]=son[now][i];
        init2(son[now][i]);
    }
}
int LCA(int A,int B)
{
    while(top[A]!=top[B])
    {
        if(depth[top[A]]<depth[top[B]])
        {
            B=fa[top[B]];
        }
        else
        {
            A=fa[top[A]];
        }
    }
    return depth[A]<depth[B]?A:B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>r;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init1(r);
    top[r]=r;
    init2(r);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}