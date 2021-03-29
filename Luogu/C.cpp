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
int n,b[300005],ans;
map<int,pair<int,int> > a;
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
    for(int i=1;i<=n;++i)
    {
        read(b[i]);
        ++a[b[i]].first;
    }
    for(map<int,pair<int,int> > :: iterator i=a.begin();i!=a.end();++i)
    {
        i->second.second=i->first*i->second.first;
        if(i->first%3==0)
        {
            i->second.second+=a[i->first/3*2].second;
        }
        ans=max(i->second.second,ans);
    }
    cout<<ans<<endl;
    return 0;
}