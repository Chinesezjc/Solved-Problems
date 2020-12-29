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
int n,m,r,a,b,fa[500005][20],depth[500005];
vector<int> son[500005];
void init(int now)
{
    for(int i=1;1<<i<=depth[now];++i)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(fa[now][0]==son[now][i])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]][0]=now;
        depth[son[now][i]]=depth[now]+1;
        init(son[now][i]);
    }
}
int LCA(int A,int B)
{
    if(depth[A]<depth[B])
    {
        swap(A,B);
    }
    for(int i=19;i>=0;--i)
    {
        if(depth[A]-depth[B]>=1<<i)
        {
            A=fa[A][i];
        }
    }
    if(A==B)
    {
        return A;
    }
    for(int i=19;i>=0;--i)
    {
        if(fa[A][i]!=fa[B][i])
        {
            A=fa[A][i];
            B=fa[B][i];
        }
    }
    return fa[A][0];
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
    init(r);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}