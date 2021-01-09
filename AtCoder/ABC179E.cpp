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
int n,m,x,dfn[100005],tim,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>x>>m;
    for(int i=1;i<=n;++i)
    {
        if(!dfn[x])
        {
            dfn[x]=++tim;
            ans+=x;
        }
        else
        {
            int sum=0,len=tim-dfn[x]+1,now=x;
            do
            {
                now=now*now%m;
                sum+=now;
            }
            while(now!=x);
            int Left=n-tim;
            ans+=(Left/len)*sum;
            Left%=len;
            while(Left--)
            {
                ans+=x;
                x=x*x%m;
            }
            break;
        }
        x=x*x%m;
    }
    cout<<ans<<endl;
    return 0;
}