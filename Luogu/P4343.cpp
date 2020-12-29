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
int l,r,k,n,x[100005];
int check(int now)
{
    int v=0,kill=0;
    for(int i=1;i<=n;++i)
    {
        v+=x[i];
        if(v>=now)
        {
            ++kill;
            v=0;
        }
        if(v<0)
        {
            v=0;
        }
    }
    return kill;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    l=1;
    r=INF;
    while(l<r)
    {
        int mid=(l+r)>>1,v=check(mid);
        if(v<k)
        {
            r=mid-1;
        }
        if(v==k)
        {
            r=mid;
        }
        if(v>k)
        {
            l=mid+1;
        }
    }
    if(check(l)==k)
    {
        cout<<l<<' ';
    }
    l=1;
    r=INF;
    while(l<r)
    {
        int mid=(l+r+1)>>1,v=check(mid);
        if(v<k)
        {
            r=mid-1;
        }
        if(v==k)
        {
            l=mid;
        }
        if(v>k)
        {
            l=mid+1;
        }
    }
    if(check(r)==k)
    {
        cout<<r<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}