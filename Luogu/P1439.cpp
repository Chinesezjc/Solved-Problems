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
int n,dp[100005],cnt;
struct L{
    int v,p,l;
}a[100005],b[100005];
bool cmp_v(const L &A,const L &B)
{
    return A.v<B.v;
}
bool cmp_p(const L &A,const L &B)
{
    return A.p<B.p;
}
bool cmp_l(const L &A,const L &B)
{
    return A.l<B.l;
}
void work(int now)
{
    int l=1,r=cnt;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(dp[mid]>now)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    dp[l]=now;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].v;
        a[i].p=i;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>b[i].v;
        b[i].p=i;
    }
    sort(a+1,a+1+n,cmp_v);
    sort(b+1,b+1+n,cmp_v);
    for(int i=1;i<=n;++i)
    {
        a[i].l=b[i].p;
        b[i].l=a[i].p;
    }
    sort(a+1,a+1+n,cmp_p);
    sort(b+1,b+1+n,cmp_p);
    for(int i=1;i<=n;++i)
    {
        if(a[i].l>dp[cnt])
        {
            dp[++cnt]=a[i].l;
        }
        else
        {
            work(a[i].l);
        }
    }
    cout<<cnt<<endl;
    return 0;
}