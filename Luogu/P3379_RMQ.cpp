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
int n,m,r,a,b,dfn[1000005],ST[1000005][20],depth[500005],appear[500005],tim,lg[1000005];
vector<int> son[500005];
void init(int now)
{
    dfn[++tim]=now;
    appear[now]=tim;
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(appear[son[now][i]])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        depth[son[now][i]]=depth[now]+1;
        init(son[now][i]);
        dfn[++tim]=now;
    }
}
void read(int &x)
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
void writeln(int x)
{
    char TMP[16];
    int cnt=0;
    while(x)
    {
        TMP[cnt++]=x%10^'0';
        x/=10;
    }
    while(cnt--)
    {
        putchar(TMP[cnt]);
    }
    putchar('\n');
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin>>n>>m>>r;
    read(n);
    read(m);
    read(r);
    for(int i=1;i<n;++i)
    {
        // cin>>a>>b;
        read(a);
        read(b);
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(r);
    for(int i=1;i<=tim;++i)
    {
        ST[i][0]=dfn[i];
    }
    for(int i=1;1<<i<=tim;++i)
    {
        for(int j=1;j+(1<<i)-1<=tim;++j)
        {
            ST[j][i]=(depth[ST[j][i-1]]<depth[ST[j+(1<<i>>1)][i-1]]?ST[j][i-1]:ST[j+(1<<i>>1)][i-1]);
        }
    }
    for(int i=1;1<<i<=tim;++i)
    {
        ++lg[1<<i];
    }
    for(int i=1;i<=tim;++i)
    {
        lg[i]+=lg[i-1];
    }
    for(int i=1;i<=m;++i)
    {
        // cin>>a>>b;
        read(a);
        read(b);
        if(appear[a]>appear[b])
        {
            swap(a,b);
        }
        int A=ST[appear[a]][lg[appear[b]-appear[a]+1]];
        int B=ST[appear[b]-(1<<lg[appear[b]-appear[a]+1])+1][lg[appear[b]-appear[a]+1]];
        // cout<<(depth[A]<depth[B]?A:B)<<endl;
        writeln(depth[A]<depth[B]?A:B);
    }
    return 0;
}