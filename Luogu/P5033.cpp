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
int n,dp[1005][25],x[1005],y[1005];
char v[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i]>>v[i];
    }
    for(int i=2;i<=n;++i)
    {
        fill(dp[i]+1,dp[i]+1+20,INF);
    }
    for(int i=2;i<=n;++i)
    {
        // cout<<i<<endl;
        if(v[i]=='P')
        {
            for(int j=i-1;j>0&&x[i]-x[j]<=4;--j)
            {
                if(y[i]==y[j]&&x[i]-x[j]<=4)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]==y[j]+1&&x[i]-x[j]<=3)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]<=y[j]&&x[i]-x[j]<=1)
                {
                    for(int k=1;k<=20;++k)
                    {
                        if(k+max(y[j]-y[i]-3,0ll)>20)
                        {
                            break;
                        }
                        dp[i][k]=min(dp[i][k],dp[j][k+max(y[j]-y[i]-3,0ll)]);
                    }
                }
            }
        }
        if(v[i]=='N')
        {
            for(int j=i-1;j>0&&x[i]-x[j]<=4;--j)
            {
                if(y[i]==y[j]&&x[i]-x[j]<=4)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]==y[j]+1&&x[i]-x[j]<=3)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]<=y[j]&&x[i]-x[j]<=1)
                {
                    for(int k=1;k<=20;++k)
                    {
                        if(k+max(y[j]-y[i]-3,0ll)>20)
                        {
                            break;
                        }
                        dp[i][k]=min(dp[i][k],dp[j][k+max(y[j]-y[i]-3,0ll)]);
                        if(x[i+1]-x[i]==1)
                        {
                            int h=y[i]+(y[j]-y[i])*0.6;
                            if(h>=y[i+1]&&k+(h-y[i+1]-3)>0)
                            {
                                dp[i+1][k]=min(dp[i+1][k],dp[j][k+max(h-y[i+1]-3,0ll)]);
                            }
                        }
                    }
                }
            }
        }
        if(v[i]=='Z')
        {
            for(int j=i-1;j>0&&x[i]-x[j]<=4;--j)
            {
                if(y[i]==y[j]&&x[i]-x[j]<=4)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]==y[j]+1&&x[i]-x[j]<=3)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]+1);
                    }
                }
                if(y[i]<=y[j]&&x[i]-x[j]<=1)
                {
                    for(int k=1;k<=20;++k)
                    {
                        dp[i][k]=min(dp[i][k],dp[j][k]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=20;++j)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=20;i>0;--i)
    {
        if(dp[n][i]<INF)
        {
            cout<<dp[n][i]<<endl;
            return 0;
        }
    }
    cout<<"qwq"<<endl;
    return 0;
}