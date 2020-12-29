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
#define INF 0x3fffffffffffffff
using namespace std;
const long double PI=acos(-1);
const long double eps=0.0000000001;
struct person
{
    int num[25];
    int& operator [] (const int tmp)
    {
        return num[tmp];
    }
}man[25],woman[25];
int n,dp[25][1<<20];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>man[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>woman[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<1<<n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                if(j&(1<<k>>1))
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<k>>1)]+man[i][k]*woman[k][i]);
                }
            }
        }
    }
    cout<<dp[n][(1<<n)-1]<<endl;
    return 0;
}