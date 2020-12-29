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
#define PI 3.14159265358979323
#define INF 0x3fffffff
using namespace std;
int n,a,b,dis[5005],g[5005],l[5005];
long long ans;
vector<int> to[5005];
queue<int> que;
void bfs(int s)
{
    fill(dis+1,dis+1+n,-1);
    dis[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        for(int i=0;i<(int)to[now].size();++i)
        {
            if(~dis[to[now][i]])
            {
                continue;
            }
            dis[to[now][i]]=dis[now]+1;
            que.push(to[now][i]);
            ++g[dis[now]+1];
        }
    }
}
void bfs1(int fa,int s)
{
    fill(dis+1,dis+1+n,-1);
    dis[fa]=INF;
    dis[s]=1;
    que.push(s);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        for(int i=0;i<(int)to[now].size();++i)
        {
            if(~dis[to[now][i]])
            {
                continue;
            }
            dis[to[now][i]]=dis[now]+1;
            que.push(to[now][i]);
            ++l[dis[now]+1];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        fill(g+1,g+1+n,0);
        bfs(i);
        for(int j=1;j<=n;++j)
        {
            if(g[j]==0)
            {
                break;
            }
            ans+=g[j]*(g[j]-1ll)*(g[j]-2)/6;
            // cout<<dis[j]<<' ';
        }
        // cout<<endl;
        for(int j=0;j<(int)to[i].size();++j)
        {
            fill(l+1,l+1+n,0);
            bfs1(i,to[i][j]);
            for(int k=2;k<=n;++k)
            {
                if(l[k]==0)
                {
                    break;
                }
                ans-=l[k]*(l[k]-1ll)*(g[k]-l[k])/2;
                ans-=l[k]*(l[k]-1ll)*(l[k]-2)/6;
            }
        }
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}