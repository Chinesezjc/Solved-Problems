#include<cstdio>
using namespace std;
int now,x,has;
int main()
{
	for(int i=1;i<=12;++i)
	{
		scanf("%d",&x);
		now+=300;
		now-=x;
		if(now<0)
		{
			printf("%d",-i);
			return 0;
		}
		has+=now/100;
		now%=100;
	}
	printf("%d",now+has*120);
	return 0;
}
