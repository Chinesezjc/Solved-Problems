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
int n,m,h,v[10005],g[10005],a,b,c,l,r,dis[10005];
vector<pair<int,int> > to[10005];
queue<int> que;
bool init[10005];
int work(int now)
{
    if(v[1]>now||v[n]>now)
    {
        return INF;
    }
    fill(dis+2,dis+1+n,INF);
    que.push(1);
    init[1]=true;
    while(!que.empty())
    {
        int u=que.front();
        init[u]=false;
        que.pop();
        for(int i=0;i<(int)to[u].size();++i)
        {
            if(v[to[u][i].second]<=now&&dis[to[u][i].second]>dis[u]+to[u][i].first)
            {
                dis[to[u][i].second]=dis[u]+to[u][i].first;
                if(!init[to[u][i].second])
                {
                    init[to[u][i].second]=true;
                    que.push(to[u][i].second);
                }
            }
        }
    }
    return dis[n];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>h;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i];
        g[i]=v[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        to[a].push_back(make_pair(c,b));
        to[b].push_back(make_pair(c,a));
    }
    sort(g+1,g+1+n);
    l=1;
    r=n+1;
    g[r]=INF;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(work(g[mid])<=h)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(g[l]==INF)
    {
        cout<<"AFK"<<endl;
    }
    else
    {
        cout<<g[l]<<endl;
    }
    return 0;
}