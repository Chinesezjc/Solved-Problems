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
int n,m,ST[18][100005],lg[100005],a,b;
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
void writeln(int now)
{
    char TMP[10];
    int cnt=0;
    while(now)
    {
        TMP[cnt++]=now%10+'0';
        now/=10;
    }
    while(cnt--)
    {
        putchar(TMP[cnt]);
    }
    putchar('\n');
}
signed main()
{
    ios::sync_with_stdio(false);
    read(n);
    read(m);
    for(int i=1;i<=n;++i)
    {
        read(ST[0][i]);
    }
    for(int i=1;1<<i<=n;++i)
    {
        ++lg[1<<i];
        for(int j=1;j+(1<<i)-1<=n;++j)
        {
            ST[i][j]=max(ST[i-1][j],ST[i-1][j+(1<<i>>1)]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        lg[i]+=lg[i-1];
    }
    for(int i=1;i<=m;++i)
    {
        read(a);
        read(b);
        writeln(max(ST[lg[b-a+1]][a],ST[lg[b-a+1]][b-(1<<lg[b-a+1])+1]));
    }
    return 0;
}