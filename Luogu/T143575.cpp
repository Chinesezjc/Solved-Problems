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
int sum[2000005],sumn,summ,n,m,MOD,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>MOD;
    if(n>m)
    {
        swap(n,m);
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=i;j<=m;j+=i)
        {
            ++sum[j];
        }
    }
    for(int i=1;i<=m;++i)
    {
        sumn=0;
        for(int j=i;j<=n;j+=i)
        {
            sumn+=sum[j];
        }
        summ=sumn;
        for(int j=n/i*i+i;j<=m;j+=i)
        {
            summ+=sum[j];
        }
        summ%=MOD;
        sumn%=MOD;
        (ans+=summ*sumn)%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}