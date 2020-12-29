//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int start[5][5],ans=INF;
void dfs(int x,int y,int cho)
{
	if(ans<=cho)
	{
		return;
	}
	if(x==4)
	{
		bool flag=true;
		for(int i=1;i<=3;++i)
		{
			for(int j=1;j<=3;++j)
			{
				if(!start[i][j])
				{
					flag=false;
					break;
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(flag)
		{
			ans=cho;
		}
		return;
	}
	int nx=(x+(y==3?1:0)),ny=(y==3?1:y+1);
	dfs(nx,ny,cho);
	start[x-1][y]^=1;
	start[x][y-1]^=1;
	start[x][y]^=1;
	start[x+1][y]^=1;
	start[x][y+1]^=1;
	dfs(nx,ny,cho+1);
	start[x-1][y]^=1;
	start[x][y-1]^=1;
	start[x][y]^=1;
	start[x+1][y]^=1;
	start[x][y+1]^=1;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			cin>>start[i][j];
		}
	}
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}

