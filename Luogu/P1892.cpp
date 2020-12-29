#include<cstdio>
using namespace std;
int fa[2001],n,m,x,y,ans;
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
bool get()
{
	char c=getchar();
	while(c!='F'&&c!='E')
	{
		c=getchar();
	}
	return c=='F'?true:false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n<<1;++i)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		if(get())
		{
			scanf("%d%d",&x,&y);
			fa[find(x)]=find(y);
		}
		else
		{
			scanf("%d%d",&x,&y);
			fa[find(x+n)]=find(y);
			fa[find(y+n)]=find(x);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(fa[i]==i)
		{
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}
