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
int n,m,dis[35][35],a[35][35],way[35][35],tx,ty;
vector<pair<int,int> > to[35][35];
const int xx[]={-1,1,2,2,1,-1,-2,-2},yy[]={-2,-2,-1,1,2,2,1,-1};
bool vis[35][35];
queue<pair<int,int> > dl;
void add(int x,int y,int i,int j)
{
    if(x==i&&y==j)
    {
        memset(vis,false,sizeof(vis));
        vis[x][y]=true;
    }
    for(int k=0;k<8;++k)
    {
        if(i+xx[k]<=0||j+yy[k]<=0||i+xx[k]>n||j+yy[k]>m||vis[i+xx[k]][j+yy[k]])
        {
            continue;
        }
        vis[i+xx[k]][j+yy[k]]=true;
        if((a[i+xx[k]][j+yy[k]]|4)==4)
        {
            to[x][y].push_back(make_pair(i+xx[k],j+yy[k]));
        }
        if(a[i+xx[k]][j+yy[k]]==1)
        {
            add(x,y,i+xx[k],j+yy[k]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==4)
            {
                dis[i][j]=-1;
                tx=i;ty=j;
            }
            if(a[i][j]==0)
            {
                add(i,j,i,j);
                dis[i][j]=-1;
            }
            if(a[i][j]==3)
            {
                add(i,j,i,j);
                dl.push(make_pair(i,j));
                way[i][j]=1;
            }
        }
    }
    while(!dl.empty())
    {
        pair<int,int> now=dl.front();
        dl.pop();
        for(int i=0;i<(int)to[now.first][now.second].size();++i)
        {
            #define X to[now.first][now.second][i].first
            #define Y to[now.first][now.second][i].second
            if(~dis[X][Y])
            {
                if(dis[X][Y]==dis[now.first][now.second]+1)
                {
                    way[X][Y]+=way[now.first][now.second];
                }
                continue;
            }
            dis[X][Y]=dis[now.first][now.second]+1;
            way[X][Y]=way[now.first][now.second];
            dl.push(make_pair(X,Y));
            #undef X
            #undef Y
        }
    }
    if(~dis[tx][ty])
    {
        cout<<dis[tx][ty]-1<<endl<<way[tx][ty]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}