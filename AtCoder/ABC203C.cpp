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
int n,ans;
struct node{
    int a,b;
    friend bool operator<(const node &A,const node &B)
    {
        return A.a<B.a;
    }
}a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin>>n>>ans;
    for(int i=1;i<=n;++i)
        std::cin>>a[i].a>>a[i].b;
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        if(a[i].a<=ans)
            ans+=a[i].b;
        else break;
    std::cout<<ans<<std::endl;
    return 0;
}