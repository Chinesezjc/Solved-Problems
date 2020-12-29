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
int n,m,dis[1000005],way[1000005],a,b;
vector <int> to[1000005];
queue <int> dl;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        if(a==b)
        {
            continue;
        }
        to[a].push_back(b);
        to[b].push_back(a);
    }
    fill(dis+2,dis+1+n,-1);
    dl.push(1);
    way[1]=1;
    while(!dl.empty())
    {
        int now=dl.front();
        way[now]%=100003;
        dl.pop();
        for(int i=0;i<(int)to[now].size();++i)
        {
            if(!~dis[to[now][i]])
            {
                dis[to[now][i]]=dis[now]+1;
                dl.push(to[now][i]);
            }
            if(dis[to[now][i]]==dis[now]+1)
            {
                way[to[now][i]]+=way[now];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<way[i]<<endl;
    }
    return 0;
}