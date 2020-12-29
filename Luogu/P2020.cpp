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
int n,k,p,app[1000005],f[5000005],len[1000005],tim;
int gcd(int x,int y)
{
    return x%y?gcd(y,x%y):y;
}
void exgcd(int x,int y,int &a,int &b)
{
    if(y==1)
    {
        a=0;
        b=1;
        return;
    }
    exgcd(y,x%y,a,b);
    int aa=a,bb=b;
    a=bb;
    b=aa-x/y*bb;
}
int getg(int x,int mod)
{
    int a,b;
    exgcd(mod,x,a,b);
    return (b%mod+mod)%mod;
}
struct martix{
    int n,m,a[5][5];
    martix operator * (const martix &TMP)const
    {
        martix tmp;
        tmp.n=n;
        tmp.m=TMP.m;
        for(int i=1;i<=tmp.n;++i)
        {
            for(int j=1;j<=tmp.m;++j)
            {
                tmp.a[i][j]=0;
            }
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=tmp.n;++j)
            {
                for(int k=1;k<=tmp.m;++k)
                {
                    tmp.a[j][k]+=a[j][i]*TMP.a[i][k];
                }
            }
        }
        for(int i=1;i<=tmp.n;++i)
        {
            for(int j=1;j<=tmp.m;++j)
            {
                tmp.a[i][j]%=p;
            }
        }
        return tmp;
    }
}now,cha1,cha2;
martix st(int size)
{
    martix tmp;
    tmp.n=size;
    tmp.m=size;
    for(int i=1;i<=size;++i)
    {
        for(int j=1;j<=size;++j)
        {
            tmp.a[i][j]=0;
        }
        tmp.a[i][i]=1;
    }
    return tmp;
}
martix power(martix a,int b)
{
    martix tmp=st(3);
    while(b)
    {
        if(b&1)
        {
            tmp=tmp*a;
        }
        a=a*a;
        b>>=1;
    }
    return tmp;
}
void init()
{
    f[2]=f[0]=1;
    int cnt=3;
    do
    {
        ++cnt;
        f[cnt%3]=(f[(cnt-1)%3]+f[(cnt-2)%3])%k;
    }
    while(f[cnt%3]!=1&&cnt-3<n);
    cnt-=3;
    if(f[cnt%3]==1)
    {
        now=now*power(cha1,cnt-1)*cha2;
        tim=f[(cnt+2)%3];
    }
    else
    {
        now=now*power(cha1,cnt);
    }
    n-=cnt;
    f[1]=1;
    f[2]=1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k>>p;
    f[1]=f[2]=1;
    app[1]=1;
    for(int i=3;i<=5000000;++i)
    {
        f[i]=(f[i-1]+f[i-2])%k;
        if(!app[f[i]])
        {
            app[f[i]]=i;
        }
    }
    if(n<=2)
    {
        cout<<1<<endl;
        return 0;
    }
    now.n=1;now.m=3;
    now.a[1][1]=1;now.a[1][2]=1;now.a[1][3]=-1;
    cha1.n=3;cha1.m=3;
    cha1.a[1][1]=1;cha1.a[1][2]=1;cha1.a[1][3]=0;
    cha1.a[2][1]=1;cha1.a[2][2]=0;cha1.a[2][3]=0;
    cha1.a[3][1]=0;cha1.a[3][2]=0;cha1.a[3][3]=1;
    cha2.n=3;cha2.m=3;
    cha2.a[1][1]=1;cha2.a[1][2]=1;cha2.a[1][3]=0;
    cha2.a[2][1]=1;cha2.a[2][2]=0;cha2.a[2][3]=0;
    cha2.a[3][1]=1;cha2.a[3][2]=0;cha2.a[3][3]=1;
    n-=2;
    init();
    while(n)
    {
        if(gcd(tim,k)>1)
        {
            now=now*power(cha1,n);
            n=0;
            break;
        }
        int g=getg(tim,k);
        if(len[tim])
        {
            int TIM=f[len[tim]-1]*tim%k,LEN=len[tim];
            martix F=power(cha1,len[tim]-1)*cha2;
            while(TIM!=tim)
            {
                F=F*power(cha1,len[TIM]-1)*cha2;
                LEN+=len[TIM];
                TIM=f[len[TIM]-1]*TIM%k;
            }
            now=now*power(F,n/LEN);
            n%=LEN;
            while(n)
            {
                if(gcd(tim,k)>1)
                {
                    now=now*power(cha1,n);
                    n=0;
                    break;
                }
                int g=getg(tim,k);
                len[tim]=app[g];
                if(len[tim]<=n)
                {
                    now=now*power(cha1,len[tim]-1)*cha2;
                    n-=len[tim];
                    tim=f[len[tim]-1]*tim%k;
                }
                else
                {
                    now=now*power(cha1,n);
                    n=0;
                }
            }
            break;
        }
        len[tim]=app[g];
        if(len[tim]<=n)
        {
            now=now*power(cha1,len[tim]-1)*cha2;
            n-=len[tim];
            tim=f[len[tim]-1]*tim%k;
        }
        else
        {
            now=now*power(cha1,n);
            n=0;
        }
    }
    cout<<now.a[1][1]<<endl;
    return 0;
}