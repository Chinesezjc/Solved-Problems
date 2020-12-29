//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,v1,v2,ans;
int a[102][102][102],b[31];
void dfs(int nn,int t,int u1,int k1,int u2,int k2)
{
	if(t>=ans)
	{
		return;
	}
	if(nn>m)
	{
		ans=t;
		return;
	}
	int g[30],k;
	for(int i=1;i<=m;++i)
	{
		g[i]=b[i];
	}
	if(k1+1==nn)
	{
		k=max(t,u1+a[nn][k1][nn]/v1);
		if(nn==1)
		{
			for(int i=1;i<=m;++i)
			{
				b[i]/=v2;
			}
		}
		for(int i=nn+1;i<=m;++i)
		{
			b[i]=min(b[i],max(b[nn],k)+a[nn][nn][i]/v2);
		}
	}
	else
	{
		k=max(t,b[nn]);
		b[nn]=t+a[nn-1][nn-1][nn]/v2;
		for(int i=nn+1;i<=m;++i)
		{
			b[i]=min(t+a[nn-1][nn-1][i]/v2,max(b[nn],k)+a[nn][nn][i]/v2);
		}
	}
	dfs(nn+1,k,k,nn,u2,k2);
	if(k2+1==nn)
	{
		k=max(t,u2+a[nn][k2][nn]/v2);
		if(nn==1)
		{
			for(int i=1;i<=m;++i)
			{
				g[i]/=v1;
			}
		}
		for(int i=nn+1;i<=m;++i)
		{
			b[i]=min(g[i],max(g[nn],k)+a[nn][nn][i]/v1);
		}
	}
	else
	{
		k=max(t,g[nn]);
		b[nn]=t+a[nn-1][nn-1][nn]/v1;
		for(int i=nn+1;i<=m;++i)
		{
			b[i]=min(t+a[nn-1][nn-1][i]/v1,max(b[nn],k)+a[nn][nn][i]/v1);
		}
	}
	dfs(nn+1,k,u1,k1,k,nn);
	for(int i=1;i<=m;++i)
	{
		b[i]=g[i];
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>v1>>v2;
	for(int i=1;i<=n;++i)
	{
		cin>>a[0][0][i];
		if(!a[0][0][i])
		{
			a[0][0][i]=INF;
		}
		a[0][i][0]=a[0][0][i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[0][i][j];
			if(!a[0][i][j])
			{
				a[0][i][j]=INF;
			}
		}
	}
	for(int k=m+1;k<=n;++k)
	{
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				a[0][i][j]=min(a[0][i][j],a[0][i][k]+a[0][k][j]);
			}
		}
	}
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				a[i][j][k]=min(a[i][j][k],a[i][j][i]+a[i][i][k]);
				a[i+1][j][k]=a[i][j][k];
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		b[i]=a[0][0][i];
	}
	ans=INF;
	dfs(1,0,0,0,0,0);
	cout<<ans<<endl;
	return 0;
}

