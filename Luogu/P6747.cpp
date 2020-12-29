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
#define pi 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[100005],ans,q,m;
__int128 v[2][60],sum;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        for(int j=0;j<=59;++j)
        {
            if(a[i]&(1ll<<j))
            {
                v[0][j]+=1ll<<j;
            }
            else
            {
                v[1][j]+=1ll<<j;
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>m;
        int tmp=59;
        ans=0;
        sum=0;
        for(int j=tmp;j>=0;--j)
        {
            if(v[0][j]<v[1][j])
            {
                sum+=v[0][j];
            }
            else
            {
                sum+=v[1][j];
                ans+=1ll<<j;
            }
        }
        if(sum>m)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int j=tmp;j>=0;--j)
        {
            if(ans&(1ll<<j))
            {
                continue;
            }
            if(sum-v[0][j]+v[1][j]<=m)
            {
                ans+=1ll<<j;
                sum+=v[1][j]-v[0][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}