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
#define pi 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[500005],f,t,fa[500005],depth[500005],root,ans,v[500005];
vector<int> to[500005];
bool islian()
{
    int size1=0;
    for(int i=1;i<=n;++i)
    {
        if(to[i].size()>2)
        {
            return false;
        }
        if(to[i].size()==1)
        {
            ++size1;
        }
    }
    return size1==2;
}
bool isjuhua()
{
    for(int i=1;i<=n;++i)
    {
        if(to[i].size()==n-1)
        {
            return true;
        }
    }
    return false;
}
void dfs(int now)
{
    for(int i=0;i<(int)to[now].size();++i)
    {
        if(fa[now]=to[now][i])
        {
            continue;
        }
        depth[to[now][i]]=depth[now]+1;
        fa[to[now][i]]=now;
        dfs(to[now][i]);
    }
}
void solve_for_lian()
{
    for(int i=1;i<=n;++i)
    {
        if(to[i].size()==1)
        {
            root=i;
            dfs(i);
            break;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<(int)to[i].size();++j)
        {
            ans+=min(a[i],a[to[i][j]]);
        }
    }
    cout<<(ans>>1)<<endl;
}
void solve_for_juhua()
{
    for(int i=1;i<=n;++i)
    {
        if(to[i].size()==n-1)
        {
            root=i;
            dfs(i);
            break;
        }
    }
    for(int i=1;i<root;++i)
    {
        v[i]=a[i];
    }
    for(int i=root+1;i<=n;++i)
    {
        v[i-1]=a[i];
    }
    sort(v+1,v+n);
    int mid=(n-1)/2+1;
    for(int i=mid;i>0;--i)
    {
        if(v[i]>a[root])
        {
            v[i]=a[root];
        }
    }
    for(int i=1;i<n;++i)
    {
        ans+=v[i];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;++i)
    {
        cin>>f>>t;
        to[f].push_back(t);
        to[t].push_back(f);
    }
    if(islian())
    {
        solve_for_lian();
        return 0;
    }
    if(isjuhua())
    {
        solve_for_juhua();
        return 0;
    }
    cout<<n-1<<endl;
    return 0;
}