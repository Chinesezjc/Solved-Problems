#include<cstdio>
using namespace std;
int n,m,num[1025][1025];
void dfs(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)
	{
		num[x1][y1]=1;
		return;
	}
	int a=(x1+x2)/2,b=(y1+y2)/2;
	for(int i=x1;i<=a;++i)
	{
		for(int j=y1;j<=b;++j)
		{
			num[i][j]=0;
		}
	}
	dfs(x1,b+1,a,y2);
	dfs(a+1,y1,x2,b);
	dfs(a+1,b+1,x2,y2);
}
int main()
{
	scanf("%d",&n);
	m=1<<n;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=m;++j)
		{
			num[i][j]=-1;
		}
	}
	dfs(1,1,m,m);
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=m;++j)
		{
			printf("%d ",num[i][j]);
		}
		puts("");
	}
	return 0;
}
