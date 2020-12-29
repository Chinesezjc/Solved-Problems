//This code was made by Chinese_zjc_
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[10][10],b[10][10];
bool hang[10][10],fang[5][5][10],lie[10][10];
char tmp;
void print()
{
	for(int i=1;i<=n*n;++i)
	{
		for(int j=1;j<=n*n;++j)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
}
int gethang(int x,int y)
{
	return x;
}
int getlie(int x,int y)
{
	return y;
}
pair<int,int> getfang(int x,int y)
{
	return make_pair((x+n-1)/n,(y+n-1)/n);
}
void dfs(int x,int y)
{
	if(x>n*n)
	{
		print();
		exit(0);
	}
	if(a[x][y])
	{
		b[x][y]=a[x][y];
		dfs(x+(y==n*n),y==n*n?1:y+1);
	}
	else
	{
		int h=gethang(x,y),l=getlie(x,y);
		pair<int,int> S=getfang(x,y);
		for(int i=1;i<=n*n;++i)
		{
			if(hang[h][i]||lie[l][i]||fang[S.first][S.second][i])
			{
				continue;
			}
			hang[h][i]=lie[l][i]=fang[S.first][S.second][i]=true;
			b[x][y]=i;
			dfs(x+(y==n*n),y==n*n?1:y+1);
			hang[h][i]=lie[l][i]=fang[S.first][S.second][i]=false;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	n=3;
	for(int i=1;i<=n*n;++i)
	{
		for(int j=1;j<=n*n;++j)
		{
			cin>>tmp;
			a[i][j]=tmp^'0';
			if(a[i][j])
			{
				pair<int,int> S=getfang(i,j);
				hang[gethang(i,j)][a[i][j]]=true;
				lie[getlie(i,j)][a[i][j]]=true;
				fang[S.first][S.second][a[i][j]]=true;
			}
		}
	}
	dfs(1,1);
	cout<<"NO SOLUTION"<<endl;
	return 0;
}
