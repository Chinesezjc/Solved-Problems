//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int s[101][101],n,m,a,b,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			s[i][j]=INF;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		s[a][b]=min(s[a][b],c);
	}
	for(int i=1;i<=n;++i)
	{
		cout<<i<<':'<<endl;
		for(int j=1;j<=n;++j)
		{
			if(s[i][j]!=INF)
			{
				cout<<j<<' '<<s[i][j]<<endl;
			}
		}
	}
	return 0;
}

