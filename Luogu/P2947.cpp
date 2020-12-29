#include<cstdio>
using namespace std;
struct cow{
	int v,p;
}cow[100001];
int n,r,x,i,ans[100001];
int main()
{
	scanf("%d",&n);
	while(i<n)
	{
		++i;
		scanf("%d",&x);
		while(x>cow[r].v&&0<r)
		{
			ans[cow[r].p]=i;
			--r;
		}
		++r;
		cow[r].p=i;
		cow[r].v=x;
	}
	i=0;
	while(i<n)
	{
		++i;
		printf("%d\n",ans[i]);
	}
	return 0;
}
