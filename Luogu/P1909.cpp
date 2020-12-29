#include<cstdio>
using namespace std;
int need,a[4],b[4],ans=2000000000;
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	scanf("%d",&need);
	for(int i=1;i<=3;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(need%a[i]==0)
		{
			ans=min(need/a[i]*b[i],ans); 
		}
		else
		{
			ans=min((need/a[i]+1)*b[i],ans);
		}
	}
	printf("%d",ans);
	return 0;
}
