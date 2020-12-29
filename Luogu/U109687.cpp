//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct dis{
	int d[301][301];
}a;
inline void read(int &x)
{
	x=0;
	int TMP=1;
	char c=getchar();
	while(('0'>c||'9'<c)&&c!='-')
	{
		c=getchar();
	}
	if(c=='-')
	{
		TMP=-1;
		c=getchar();
	}
	while('0'<=c&&'9'>=c)
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	x*=TMP;
}
inline void write(int now)
{
	if(now/10)
	{
		write(now/10);
	}
	putchar(now%10+'0');
}
int n,q,ans[301][301],K,S;
void FUCK(int l,int r,dis now)
{
	if(l==r)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==l)
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				if(now.d[i][j]==INF||j==l)
				{
					--ans[l][i];
					continue;
				}
				ans[l][i]+=now.d[i][j];
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	dis nxt;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			nxt.d[i][j]=now.d[i][j];
		}
	}
	for(int k=l;k<=mid;++k)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==k||nxt.d[i][k]==INF)
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				if(i==j||k==j||nxt.d[i][k]+nxt.d[k][j]>=nxt.d[i][j])
				{
					continue;
				}
				nxt.d[i][j]=nxt.d[i][k]+nxt.d[k][j];
			}
		}
	}
	FUCK(mid+1,r,nxt);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			nxt.d[i][j]=now.d[i][j];
		}
	}
	for(int k=mid+1;k<=r;++k)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==k||nxt.d[i][k]==INF)
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				if(i==j||k==j||nxt.d[i][k]+nxt.d[k][j]>=nxt.d[i][j])
				{
					continue;
				}
				nxt.d[i][j]=nxt.d[i][k]+nxt.d[k][j];
			}
		}
	}
	FUCK(l,mid,nxt);
}
signed main()
{
	read(n);
	read(q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			read(a.d[i][j]);
			if(a.d[i][j]==-1)
			{
				a.d[i][j]=INF;
			}
		}
	}
	FUCK(1,n,a);
	for(int i=1;i<=q;++i)
	{
		read(K);
		read(S);
		if(ans[K][S]==0)
		{
			puts("0");
		}
		else
		{
			if(ans[K][S]<0)
			{
				putchar('-');
				write(-ans[K][S]);
			}
			else
			{
				write(ans[K][S]);
			}
			puts("");
		}
	}
	return 0;
}

