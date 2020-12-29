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
string a;
int n,zi[200005],mu[200005],_2[200005],_5[200005],sum[105][55],ans;
int gcd(int A,int B)
{
    return A%B?gcd(B,A%B):B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        mu[i]=1;
        bool g=false;
        for(int j=0;j<(int)a.length();++j)
        {
            if(a[j]=='.')
            {
                g=true;
            }
            if('0'<=a[j]&&a[j]<='9')
            {
                zi[i]=(zi[i]<<3)+(zi[i]<<1)+(a[j]^'0');
                if(g)
                {
                    mu[i]=(mu[i]<<3)+(mu[i]<<1);
                }
            }
        }
        while(zi[i]%2==0)
        {
            zi[i]/=2;
            ++_2[i];
        }
        while(zi[i]%5==0)
        {
            zi[i]/=5;
            ++_5[i];
        }
        while(mu[i]%2==0)
        {
            mu[i]/=2;
            --_2[i];
        }
        while(mu[i]%5==0)
        {
            mu[i]/=5;
            --_5[i];
        }
        ++sum[_2[i]+50][_5[i]+25];
    }
    for(int i=-50;i<=50;++i)
    {
        for(int j=-25;j<=25;++j)
        {
            for(int i1=-i;i1<=50;++i1)
            {
                for(int j1=-j;j1<=25;++j1)
                {
                    ans+=sum[i+50][j+25]*sum[i1+50][j1+25];
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(_2[i]>=0&&_5[i]>=0)
        {
            --ans;
        }
    }
    ans>>=1;
    cout<<ans<<endl;
    return 0;
}