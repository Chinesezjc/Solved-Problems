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
int n,m,t,fx,fy,tx,ty,ans;
bool can[7][7];
inline void dfs(int x,int y)
{
	if(x==tx&&y==ty)
	{
		++ans;
		return;
	}
	can[x][y]=true;
	if(!can[x+1][y])
	{
		dfs(x+1,y);
	}
	if(!can[x-1][y])
	{
		dfs(x-1,y);
	}
	if(!can[x][y+1])
	{
		dfs(x,y+1);
	}
	if(!can[x][y-1])
	{
		dfs(x,y-1);
	}
	can[x][y]=false;
}
signed main()
{
	rd(n);
	rd(m);
	rd(t);
	rd(fx);
	rd(fy);
	rd(tx);
	rd(ty);
	for(int i=1;i<=n;++i)
	{
		can[i][0]=true;
		can[i][m+1]=true;
	}
	for(int i=1;i<=m;++i)
	{
		can[0][i]=true;
		can[m+1][i]=true;
	}
	for(int i=1;i<=t;++i)
	{
		int x,y;
		rd(x);
		rd(y);
		can[x][y]=true;
	}
	dfs(fx,fy);
	printf("%lld",ans);
	return 0;
}

