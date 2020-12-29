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
int n,t,A,B;
double ans;
struct L{
    int siz;
    double per;
    bool operator <(const L &TMP)const
    {
        return per<TMP.per;
    }
}a[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>t;
    for(int i=1;i<=n;++i)
    {
        cin>>A>>B;
        a[i].siz=A;
        a[i].per=B*1.0/A;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>0;--i)
    {
        ans+=min(t,a[i].siz)*a[i].per;
        t-=min(t,a[i].siz);
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}