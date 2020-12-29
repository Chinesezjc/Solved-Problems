#include<cstdio>
using namespace std;
int n,m,p[2001],x,ansl,ansr,l=1,r,a[1000001];
int main()
{
	scanf("%d%d",&n,&m);
	{
		int need=m;
		while(need>0)
		{
			++r;
			scanf("%d",&a[r]);
			if(!p[a[r]])
			{
				--need;
			}
			++p[a[r]];
			while(p[a[l]]>1)
			{
				--p[a[l]];
				++l;
			}
		}
	}
	ansl=l;
	ansr=r;
	while(r<n)
	{
		++r;
		scanf("%d",&a[r]);
		++p[a[r]];
		while(p[a[l]]>1)
		{
			--p[a[l]];
			++l;
		}
		if(r-l<ansr-ansl)
		{
			ansr=r;
			ansl=l;
		}
	}
	printf("%d %d",ansl,ansr);
	return 0;
}
