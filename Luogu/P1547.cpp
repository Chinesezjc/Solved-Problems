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
int n,m,fa[2005],ans;
struct way
{
    int f,t,v;
    bool operator < (const way &TMP)const
    {
        return v<TMP.v;
    }
}w[10005];
int find(int now)
{
    return fa[now]==now?now:fa[now]=find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>w[i].f>>w[i].t>>w[i].v;
    }
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    sort(w+1,w+1+m);
    for(int i=1;i<=m;++i)
    {
        if(find(w[i].f)!=find(w[i].t))
        {
            ans=w[i].v;
            fa[find(w[i].f)]=find(w[i].t);
        }
    }
    cout<<ans<<endl;
    return 0;
}