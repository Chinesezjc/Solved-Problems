//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
char e[30][30];
int n,ans[900][30][30],endx,endy;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		e[i][0]=e[i][n+1]=e[0][i]=e[n+1][i]='X';
		for(int j=1;j<=n;++j)
		{
//			while(e[i][j]!='X'&&e[i][j]!='.'&&e[i][j]!='E'&&e[i][j]!='S')
			{
				cin>>e[i][j];
			}
			if(e[i][j]=='S')
			{
				ans[0][i][j]=1;
			}
			if(e[i][j]=='E')
			{
				endx=i;
				endy=j;
			}
		}
	}
	for(int t=1;t<=n*n;++t)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(e[i][j]!='X')
				{
					ans[t][i][j]=ans[t-1][i-1][j]+ans[t-1][i][j-1]+ans[t-1][i+1][j]+ans[t-1][i][j+1];
					if(ans[t][i][j])
					{
						e[i][j]='X';
					}
				}
			}
		}
		if(ans[t][endx][endy])
		{
			cout<<t<<endl<<ans[t][endx][endy];
			return 0;
		}
	}
	return 0;
}

