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
int n,p[10005],cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=2;i*i<=n;++i)
    {
        while(n%i==0)
        {
            p[++cnt]=i;
            n/=i;
        }
    }
    if(n>1)
    {
        p[++cnt]=n;
        n/=n;
    }
    if(cnt==1)
    {
        cout<<1<<endl<<0<<endl;
    }
    if(cnt==2)
    {
        cout<<2<<endl;
    }
    if(cnt>2)
    {
        cout<<1<<endl<<p[1]*p[2]<<endl;
    }
    return 0;
}