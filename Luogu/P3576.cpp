//This Code was made by Chinese_zjc_.
#pragma GCC optimize("Ofast")
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
signed root1,root2,n,g,k,s[1000005],a,b,fa[1000005];
int v[1000005],ans;
vector<signed> son[1000005];
inline void dfs(register signed now)
{
    if(s[g]<k*v[now])
    {
        return;
    }
    for(register signed i=0;i<(signed)son[now].size();++i)
    {
        if(fa[now]==son[now][i])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            break;
        }
    }
    for(register signed i=0;i<(signed)son[now].size();++i)
    {
        v[son[now][i]]=v[now]*son[now].size();
        fa[son[now][i]]=now;
        dfs(son[now][i]);
    }
    if(son[now].empty())
    {
        signed l=1,r=g,L,R=g;
        while(l<r)
        {
            signed mid=(l+r)>>1;
            if(s[mid]/v[now]>k)
            {
                R=r=mid-1;
                continue;
            }
            if(s[mid]<k*v[now])
            {
                l=mid+1;
                continue;
            }
            r=mid;
        }
        L=l;r=R;
        if(s[L]/v[now]!=k)
        {
            return;
        }
        while(l<r)
        {
            signed mid=(l+r+1)>>1;
            if(s[mid]/v[now]>k)
            {
                r=mid-1;
                continue;
            }
            if(s[mid]<k*v[now])
            {
                l=mid+1;
                continue;
            }
            l=mid;
        }
        R=r;
        ans+=R-L+1;
    }
}
void read(signed &x)
{
    x=0;
    char c=getchar();
    while('0'>c||c>'9')
    {
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^'0');
        c=getchar();
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin>>n>>g>>k;
    read(n);
    read(g);
    read(k);
    for(register signed i=1;i<=g;++i)
    {
        // cin>>s[i];
        read(s[i]);
    }
    sort(s+1,s+1+g);
    // cin>>root1>>root2;
    read(root1);
    read(root2);
    for(register signed i=2;i<n;++i)
    {
        // cin>>a>>b;
        read(a);
        read(b);
        son[a].push_back(b);
        son[b].push_back(a);
    }
    v[root1]=1;
    v[root2]=1;
    dfs(root1);
    dfs(root2);
    printf("%lld\n",ans*k);
    return 0;
}