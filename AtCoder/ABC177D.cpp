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
int n,m,fa[200005],a,b,ans,s[200005];
int find(int now)
{
    return fa[now]==now?now:fa[now]=find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        fa[find(a)]=find(b);
    }
    for(int i=1;i<=n;++i)
    {
        ++s[find(i)];
    }
    for(int i=1;i<=n;++i)
    {
        ans=max(s[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}