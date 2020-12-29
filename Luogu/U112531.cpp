//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int MB[501],MM[501],BB[501],n,m,ans;
char map[501][501];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int k=1;k<=m;++k)
			{
				MM[k]=MM[k-1]+(map[i][k]=='M'&&map[j][k]=='M'?1:0);
				BB[k]=BB[k-1]+(map[i][k]=='B'&&map[j][k]=='B'?1:0);
				MB[k]=MB[k-1]+((map[i][k]^map[j][k])==('M'^'B')?1:0);
			}
			for(int k=1;k<=m;++k)
			{
				if(map[i][k]=='M'&&map[j][k]=='M')
				{
					ans+=BB[m]-BB[k];
					ans+=MB[m]-MB[k];
				}
				if(map[i][k]=='B'&&map[j][k]=='B')
				{
					ans+=MM[m]-MM[k];
				}
				if((map[i][k]^map[j][k])==('M'^'B'))
				{
					ans+=MB[m]-MB[k];
					ans+=MM[m]-MM[k];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

