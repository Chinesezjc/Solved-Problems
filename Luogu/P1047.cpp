#include<cstdio>
using namespace std;
int way[10001],x,y,n,m,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		for(int j=x;j<=y;++j)
		{
			way[j]=true;
		}
	}
	for(int i=0;i<=n;++i)
	{
		if(!way[i])
		{
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}
