//This code was made bY Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,q,suma[2001][2001],sumb[2001][2001],X1,Y1,X2,Y2;
string a[2001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			suma[i][j]=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1];
			if(a[i][j]=='1')
			{
				++suma[i][j];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			sumb[i][j]=sumb[i-1][j]+sumb[i][j-1]-sumb[i-1][j-1];
			if(a[i][j]=='1')
			{
				if(a[i-1][j]=='1')
				{
					++sumb[i][j];
				}
				if(a[i][j-1]=='1')
				{
					++sumb[i][j];
				}
			}
		}
	}
	while(q)
	{
		--q;
		cin>>X1>>Y1>>X2>>Y2;
		cout<<suma[X2][Y2]-suma[X2][Y1-1]-suma[X1-1][Y2]+suma[X1-1][Y1-1]-sumb[X2][Y2]+sumb[X1][Y2]+sumb[X2][Y1]-sumb[X1][Y1];
	}
	return 0;
}

