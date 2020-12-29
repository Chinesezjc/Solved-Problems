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
int n,m,r,a,b,fa[500005],ans[500005];
vector<int> son[500005];
vector<pair<int,int> > g[500005];
bool vis[500005];
int find(int now)
{
    return fa[now]==now?now:fa[now]=find(fa[now]);
}
void Tarjan(int now)
{
    vis[now]=true;
    for(int i=0;i<(int)g[now].size();++i)
    {
        if(vis[g[now][i].second])
        {
            ans[g[now][i].first]=find(g[now][i].second);
        }
    }
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(vis[son[now][i]])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        Tarjan(son[now][i]);
        fa[son[now][i]]=find(now);
    }
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
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        g[a].push_back(make_pair(i,b));
        g[b].push_back(make_pair(i,a));
    }
    Tarjan(r);
    for(int i=1;i<=m;++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}