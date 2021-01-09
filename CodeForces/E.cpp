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
int t,p,ans=1,D[200005],G[200005];
int d(int now)
{
    if(D[now])
    {
        return D[now];
    }
    int tmp=0;
    for(int i=1;i*i<=now;++i)
    {
        if(now%i==0)
        {
            tmp+=2;
            if(i*i==now)
            {
                --tmp;
            }
        }
    }
    return D[now]=tmp;
}
int g(int y)
{
    if(G[y])
    {
        return G[y];
    }
    int tmp=1;
    for(int z=1;z*z<=y;++z)
    {
        if(y%z==0)
        {
            (tmp*=(z+1)*(z+1))%=p;
            if(z*z!=y)
            {
                (tmp*=(y/z+1)*(y/z+1))%=p;
            }
        }
    }
    return G[y]=tmp;
}
int power(int a,int b)
{
    int tmp=1;
    while(b)
    {
        if(b&1)
        {
            (tmp*=a)%=p;
        }
        (a*=a)%=p;
        b>>=1;
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t>>p;
    for(int x=1;x<=t;++x)
    {
        for(int y=1;y*y<=x;++y)
        {
            if(x%y==0)
            {
                (ans*=power(y,d(y))*power(g(y),p-2)%p)%=p;
                if(y*y!=x)
                {
                    (ans*=power(x/y,d(x/y))*power(g(x/y),p-2)%p)%=p;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}