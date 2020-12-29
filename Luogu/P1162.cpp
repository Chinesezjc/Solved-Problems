#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd*=xxx;
}
inline char rd(char &ddd)
{
	char tmp=getchar();
	while(tmp==' '||tmp=='\n')
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	return ddd=tmp;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
struct Queue{
	int x,y;
}que[901];
int n,x,ans[31][31],l,r;
inline void bfs(const int &x,const int &y)
{
	if(ans[x+1][y]==2)
	{
		ans[x+1][y]=0;
		++r;
		que[r].x=x+1;
		que[r].y=y;
	}
	if(ans[x-1][y]==2)
	{
		ans[x-1][y]=0;
		++r;
		que[r].x=x-1;
		que[r].y=y;
	}
	if(ans[x][y+1]==2)
	{
		ans[x][y+1]=0;
		++r;
		que[r].x=x;
		que[r].y=y+1;
	}
	if(ans[x][y-1]==2)
	{
		ans[x][y-1]=0;
		++r;
		que[r].x=x;
		que[r].y=y-1;
	}
}
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			rd(x);
			if(x==1)
			{
				ans[i][j]=1;
			}
			if(x==0)
			{
				ans[i][j]=2;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(ans[i][1]==2)
		{
			ans[i][1]=0;
			++r;
			que[r].x=i;
			que[r].y=1;
		}
		if(ans[i][n]==2)
		{
			ans[i][n]=0;
			++r;
			que[r].x=i;
			que[r].y=n;
		}
		if(ans[1][i]==2)
		{
			ans[1][i]=0;
			++r;
			que[r].x=1;
			que[r].y=i;
		}
		if(ans[n][i]==2)
		{
			ans[n][i]=0;
			++r;
			que[r].x=n;
			que[r].y=i;
		}
	}
	while(l<r)
	{
		++l;
		bfs(que[l].x,que[l].y);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			printf("%lld ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}

