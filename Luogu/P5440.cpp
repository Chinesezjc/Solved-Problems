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
int T,num[10],month[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31},ans,is[10000],p[10005],cnt;
char c;
bool isdate(int now)
{
    if(now/10000==0)
    {
        return false;
    }
    if(now%10000==229)
    {
        if(now/10000%4==0&&(now/10000%400==0||now/10000%100!=0))
        {
            return true;
        }
        return false;
    }
    if(now/100%100>12||now%100==0)
    {
        return false;
    }
    return month[now/100%100]>=now%100;
}
bool isprime(int now)
{
    if(now<10000)
    {
        return is[now];
    }
    int li=sqrt(now);
    for(int i=1;p[i]<=li&&i<=cnt;++i)
    {
        if(now%p[i]==0)
        {
            return false;
        }
    }
    // cout<<now<<endl;
    return true;
}
int power(int A,int B)
{
    int tmp=1;
    while(B)
    {
        if(B&1)
        {
            tmp*=A;
        }
        A*=A;
        B>>=1;
    }
    return tmp;
}
bool isdate1(int now)
{
    if(now==229)
    {
        return true;
    }
    if(now%100==0||now/100==0||now/100>12)
    {
        return false;
    }
    return month[now/100]>=now%100;
}
void dfs(int now,int v)
{
    if(now==8)
    {
        ans+=isdate(v)&&isprime(v);
        return;
    }
    if(now==2&&(v>31||!isprime(v)))
    {
        return;
    }
    if(now==4&&(!isdate1(v)||!isprime(v)))
    {
        return;
    }
    if(~num[now])
    {
        dfs(now+1,v+power(10,now)*num[now]);
    }
    else
    {
        for(int i=0;i<10;++i)
        {
            dfs(now+1,v+power(10,now)*i);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    memset(is,0xff,sizeof(is));
    for(int i=2;i<10000;++i)
    {
        if(!~is[i])
        {
            is[i]=true;
            p[++cnt]=i;
            for(int j=i<<1;j<10000;j+=i)
            {
                is[j]=false;
            }
        }
    }
    is[0]=is[1]=false;
    cin>>T;
    while(T--)
    {
        for(int i=7;i>=0;--i)
        {
            cin>>c;
            if(c=='-')
            {
                num[i]=-1;
            }
            else
            {
                num[i]=c^'0';
            }
        }
        bool flag=true;
        for(int i=0;i<8;++i)
        {
            if(~num[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<55157<<endl;
            continue;
        }
        dfs(0,0);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}