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
int n,m,a,b,c,add[2000005],sub[2000005],ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        add[a]+=c;
        if(b<a)
        {
            b+=n;
        }
        add[b]-=c;
    }
    for(int i=1;i<=n<<1;++i)
    {
        sub[i]=sub[i-1]+add[i];
    }
    for(int i=1;i<=n;++i)
    {
        sub[i]+=sub[i+n];
        ans=max(ans,sub[i]);
    }
    cout<<(ans+35)/36<<endl;
    return 0;
}