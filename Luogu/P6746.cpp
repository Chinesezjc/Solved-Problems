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
int ans=INF,a,b,c,d;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d;
    if(a==b)
    {
        ans=min(ans,c);
    }
    if(a==0&&b==0)
    {
        ans=min(ans,0ll);
    }
    if(a==0||b==0)
    {
        ans=min(ans,d);
    }
    ans=min(ans,c+d);
    ans=min(ans,d+d);
    cout<<ans<<endl;
    return 0;
}