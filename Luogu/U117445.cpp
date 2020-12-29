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
int T,n,m,ans,sum[105];
struct item{
    int w,v,s;
    double per;
    bool operator < (const item &TMP)const
    {
        return per>TMP.per;
    }
}a[105];
struct f{
    int now,v,used,g;
    void getg()
    {
        int l=m-used;
        g=0;
        for(int i=now;i<=n;++i)
        {
            int tmp=min(l/a[i].w+1,a[i].s);
            g+=tmp*a[i].v;
            l-=tmp*a[i].w;
            if(l<0)
            {
                return;
            }
        }
    }
    bool operator < (const f &TMP)const
    {
        return v+g<TMP.v+TMP.g;
    }
};
priority_queue<f> que;
void dfs(int now,int v,int used)
{
    if(v+sum[n]-sum[now-1]<=ans)
    {
        return;
    }
    if(now>n)
    {
        ans=v;
        return;
    }
    for(int i=min((m-used)/a[now].w,a[now].s);i>=0;--i)
    {
        dfs(now+1,v+a[now].v*i,used+a[now].w*i);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].w;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].v;
        }
        for(int i=1;i<=n;++i)
        {
            a[i].s=i;
            a[i].per=a[i].v*1.0/a[i].w;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i)
        {
            sum[i]=sum[i-1]+a[i].v*a[i].s;
        }
        f TTTTTTTTTTTTT=(f){1,0,0};
        TTTTTTTTTTTTT.getg();
        que.push(TTTTTTTTTTTTT);
        while(que.top().v+que.top().g>ans)
        {
            f u=que.top();
            ans=max(ans,u.v);
            // cout<<u.now<<' '<<u.v<<' '<<u.used<<' '<<u.g<<endl;
            que.pop();
            if(u.now>n)
            {
                continue;
            }
            for(int i=min((m-u.used)/a[u.now].w,a[u.now].s);i>=0;--i)
            {
                f nxt=(f){u.now+1,u.v+a[u.now].v*i,u.used+a[u.now].w*i};
                nxt.getg();
                que.push(nxt);
            }
        }
        cout<<ans<<endl;
        while (!que.empty())
        {
            que.pop();
        }
    }
    return 0;
}