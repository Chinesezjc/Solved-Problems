#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long fa[1001],x[1001],y[1001],n,m,cnt,need;
double ans;
struct WAY{
	long long v,x,y;
}way[1000001];
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
bool cmp(const WAY &a,const WAY &b)
{
	return a.v<b.v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		scanf("%d%d",&x[i],&y[i]);
		for(int j=1;j<i;++j)
		{
			++cnt;
			way[cnt].v=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			way[cnt].x=j;
			way[cnt].y=i;
		}
	}
	sort(way+1,way+1+cnt,cmp);
	need=n-1;
	while(m>0)
	{
		--m;
		scanf("%d%d",&x[0],&y[0]);
		if(find(x[0])!=find(y[0]))
		{
			fa[find(x[0])]=find(y[0]);
			--need;
		}
	}
	x[0]=y[0]=0; 
	for(int i=1;i<=cnt&&need>0;++i)
	{
		if(find(way[i].x)!=find(way[i].y))
		{
			fa[find(way[i].x)]=find(way[i].y);
			ans+=sqrt(way[i].v);
			--need;
		}
	}
	printf("%.2lf",ans);
}
