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
int a,b,n,Max[8][1005][1005],Min[8][1005][1005],ans,cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>n;
    for(int i=1;i<=a;++i)
    {
        for(int j=1;j<=b;++j)
        {
            cin>>cnt;
            Max[0][i][j]=cnt;
            Min[0][i][j]=cnt;            
        }
    }
    for(int k=1;1<<k<=n;++k)
    {
        cnt=k;
        for(int i=1;i+(1<<k)-1<=a;++i)
        {
            for(int j=1;j+(1<<k)-1<=b;++j)
            {
                Max[k][i][j]=max(max(Max[k-1][i][j],Max[k-1][i][j+(1<<k>>1)]),max(Max[k-1][i+(1<<k>>1)][j],Max[k-1][i+(1<<k>>1)][j+(1<<k>>1)]));
                Min[k][i][j]=min(min(Min[k-1][i][j],Min[k-1][i][j+(1<<k>>1)]),min(Min[k-1][i+(1<<k>>1)][j],Min[k-1][i+(1<<k>>1)][j+(1<<k>>1)]));
            }
        }
    }
    ans=INF;
    for(int i=1;i+n-1<=a;++i)
    {
        for(int j=1;j+n-1<=b;++j)
        {
            ans=min(ans,max(max(Max[cnt][i][j],Max[cnt][i+n-(1<<cnt)][j]),max(Max[cnt][i][j+n-(1<<cnt)],Max[cnt][i+n-(1<<cnt)][j+n-(1<<cnt)]))-min(min(Min[cnt][i][j],Min[cnt][i+n-(1<<cnt)][j]),min(Min[cnt][i][j+n-(1<<cnt)],Min[cnt][i+n-(1<<cnt)][j+n-(1<<cnt)])));
        }
    }
    cout<<ans<<endl;
    return 0;
}