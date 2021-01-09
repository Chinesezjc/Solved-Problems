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
int n,k,t[1000005],a,b,ans=-1;
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
signed main()
{
    read(n);
    read(k);
    for(int i=1;i<=n;++i)
    {
        read(a);
        read(b);
        t[a]+=b;
    }
    if(k==0)
    {
        for(int i=0;i<=1000000;++i)
        {
            if(t[i]>=2)
            {
                ans=max(ans,t[i]*i);
            }
        }
        if(~ans)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return 0;
    }
    for(int i=k;i<=1000000;++i)
    {
        if(t[i]&&t[i-k])
        {
            ans=max(ans,min(t[i],t[i-k])*(i+i-k));
        }
    }
    if(~ans)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}