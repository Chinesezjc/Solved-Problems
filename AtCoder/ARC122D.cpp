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
int n,v[1<<18|5],w[1<<18|5],fa,m,dp[1<<9|5][100005],q,a,b,cnt,V[15],W[15],tov[1<<9|5],tow[1<<9|5],lg[1<<10],ans;
int lowbit(int now)
{
    return now&(-now);
}
signed main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<=9;++i)
    {
        lg[1<<i]=i;
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    m=sqrt(n);
    for(int i=1;i<=m;++i)
    {
        for(int j=100000;j>=w[i];--j)
        {
            dp[i][j]=max(dp[i>>1][j],dp[i>>1][j-w[i]]+v[i]);
        }
        for(int j=w[i]-1;j>=0;--j)
        {
            dp[i][j]=dp[i>>1][j];
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        if(a<=m)
        {
            cout<<dp[a][b]<<endl;
        }
        else
        {
            fa=a;
            cnt=0;
            while(fa>m)
            {
                ++cnt;
                V[cnt]=v[fa];
                W[cnt]=w[fa];
                fa>>=1;
            }
            ans=0;
            ans=max(ans,dp[fa][b]);
            for(int i=1;i<1<<cnt;++i)
            {
                tow[i]=tow[i^lowbit(i)]+W[lg[lowbit(i)]+1];
                tov[i]=tov[i^lowbit(i)]+V[lg[lowbit(i)]+1];
                if(tow[i]<=b)
                {
                    ans=max(ans,dp[fa][b-tow[i]]+tov[i]);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}