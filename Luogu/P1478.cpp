#include<cstdio>
#include<algorithm>
using namespace std;
int h,s,n,apple[5001],ans=1;
int main()
{
	scanf("%d%d%d%d",&n,&s,&h,&apple[0]);
	h+=apple[0];
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&apple[0],&apple[i]);
		if(apple[0]>h)
		{
			--i;
			--n;
		}
	}
	sort(apple+1,apple+1+n);
	apple[n+1]=s+1;
	while(s>=apple[ans])
	{
		s-=apple[ans];
		++ans;
	}
	printf("%d",ans-1);
	return 0;
}
