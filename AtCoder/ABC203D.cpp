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
#include<ctime>
// #include<windows.h>
#define int long long
const int INF = 0x3fffffffffffffff;
const double PI = acos(-1);
const double eps = 1e-13;
int n,k,a[805][805],sum[805][805],lim;
bool check(int now)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j]<=now);
    for(int i=k;i<=n;++i)
        for(int j=k;j<=n;++j)
            if(sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]>=lim)
                return true;
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin>>n>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            std::cin>>a[i][j];
    lim=k*k-k*k/2;
    int l=0,r=1000000000;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    std::cout<<l<<std::endl;
    return 0;
}