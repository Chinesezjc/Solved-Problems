//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[105][105],dp[105][105],ans;
const int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int dfs(int x,int y)
{
	if(dp[x][y])
	{
		return dp[x][y];
	}
	int tmp=1;
	for(int i=0;i<4;++i)
	{
		if(a[x+xx[i]][y+yy[i]]>a[x][y])
		{
			tmp=max(tmp,dfs(x+xx[i],y+yy[i])+1);
		}
	}
	return dp[x][y]=tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
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
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}

