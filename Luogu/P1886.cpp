#include<cstdio>
using namespace std;
struct dl{
	int v,p;
}min[1000001],max[1000001];
int n,m,sl,sr,bl,br,x,i,ans[1000001];
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		while(i<n)
		{
			++i;
			scanf("%d",&ans[i]);
			printf("%d ",ans[i]);
		}
		puts("");
		i=0;
		while(i<n)
		{
			++i;
			printf("%d ",ans[i]);
		}
		return 0;
	}
	while(i<m)
	{
		++i;
		scanf("%d",&x);
		while(min[sr].v>x&&sl<=sr)
		{
			--sr;
		}
		++sr;
		min[sr].p=i;
		min[sr].v=x;
		while(max[br].v<x&&bl<=br)
		{
			--br;
		}
		++br;
		max[br].p=i;
		max[br].v=x;
	}
	printf("%d",min[sl].v);
	ans[i]=max[bl].v;
	while(i<n)
	{
		++i;
		scanf("%d",&x);
		while(min[sl].p<=i-m)
		{
			++sl;
		}
		while(min[sr].v>x&&sl<=sr)
		{
			--sr;
		}
		++sr;
		min[sr].p=i;
		min[sr].v=x;
		while(max[bl].p<=i-m)
		{
			++bl;
		}
		while(max[br].v<x&&bl<=br)
		{
			--br;
		}
		++br;
		max[br].p=i;
		max[br].v=x;
		printf(" %d",min[sl].v);
		ans[i]=max[bl].v;
	}
	puts("");
	i=m-1;
	while(i<n)
	{
		++i;
		printf("%d ",ans[i]);
	}
	return 0;
}
