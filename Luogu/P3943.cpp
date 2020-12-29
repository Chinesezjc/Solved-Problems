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
int n,k,m,dis[18][40005],l,b[70],c[20],cnt,dp[1<<17];
bool a[40005];
queue<int> que;
void bfs()
{
    fill(dis[cnt]+1,dis[cnt]+1+n+1,-1);
    dis[cnt][c[cnt]]=0;
    que.push(c[cnt]);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        for(int i=1;i<=m;++i)
        {
            int nxt=now-b[i];
            if(nxt>0&&!~dis[cnt][nxt])
            {
                dis[cnt][nxt]=dis[cnt][now]+1;
                que.push(nxt);
            }
            nxt=now+b[i];
            if(nxt<=n+1&&!~dis[cnt][nxt])
            {
                dis[cnt][nxt]=dis[cnt][now]+1;
                que.push(nxt);
            }
        }
    }
    for(int i=1;i<=n+1;++i)
    {
        if(!~dis[cnt][i])
        {
            dis[cnt][i]=INF;
        }
    }
}
int dfs(int now)
{
    if(~dp[now])
    {
        return dp[now];
    }
    dp[now]=INF;
    for(int i=1;i<=cnt;++i)
    {
        if(!(now&(1<<i>>1)))
        {
            dp[now]=min(dp[now],dfs(now|(1<<i>>1))+dis[i][n+1]);
            for(int j=i+1;j<=cnt;++j)
            {
                if(!(now&(1<<j>>1)))
                {
                    dp[now]=min(dp[now],dfs(now|(1<<i>>1)|(1<<j>>1))+dis[i][c[j]]);
                }
            }
        }
    }
    return dp[now];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k>>m;
    for(int i=1;i<=k;++i)
    {
        cin>>l;
        a[l]=true;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i-1]!=a[i])
        {
            c[++cnt]=i;
            bfs();
        }
    }
    // cout<<cnt<<endl;
    // for(int i=1;i<=cnt;++i)
    // {
    //     for(int j=1;j<=cnt;++j)
    //     {
    //         cout<<dis[i][c[j]]<<" ";
    //     }
    //     cout<<dis[i][n+1]<<endl;
    // }
    fill(dp,dp+(1<<17),-1);
    dp[(1<<cnt)-1]=0;
    cout<<dfs(0)<<endl;
    return 0;
}