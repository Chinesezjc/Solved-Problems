#include<cstdio>
using namespace std;
struct dl{
	int v,p;
}dl[2000001];
int n,m,l,r,i,x;
int main()
{
	scanf("%d%d",&n,&m);
	while(i<m)
	{
		++i;
		scanf("%d",&x);
		while(x>dl[r].v&&l<=r)
		{
			--r;
		}
		++r;
		dl[r].v=x;
		dl[r].p=i;
	}
	printf("%d\n",dl[l].v);
	while(i<n)
	{
		++i;
		scanf("%d",&x);
		while(dl[l].p<=i-m&&l<=r)
		{
			++l;
		}
		while(x>dl[r].v&&l<=r)
		{
			--r;
		}
		++r;
		dl[r].p=i;
		dl[r].v=x;
		printf("%d\n",dl[l].v);
	}
	return 0;
}
