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
int n,m,score[200005],a,b;
char c;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>score[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>c>>a>>b;
        if(c=='Q')
        {
            int res=0;
            for(int i=a;i<=b;++i)
            {
                res=max(res,score[i]);
            }
            cout<<res<<endl;
        }
        if(c=='U')
        {
            score[a]=max(score[a],b);
        }
    }
    return 0;
}