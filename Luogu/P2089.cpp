#include<cstdio>
using namespace std;
int n,ans[21]={1,10,55,210,615,1452,2850,4740,6765,8350,8953,8350,6765,4740,2850,1452,615,210,55,10,1},has[11];
void go(int now,int have)
{
	if(now==11)
	{
		if(have==n)
		{
			for(int i=1;i<=10;++i)
			{
				printf("%d ",has[i]+1);
			}
			puts("");
		}
		return;
	}
	if(have>n)
	{
		return;
	}
	for(int i=0;i<=2;++i)
	{
		has[now]=i;
		go(now+1,have+i);
	}
}
int main()
{
	scanf("%d",&n);
	if(n<10||30<n)
	{
		puts("0");
		return 0;
	}
	printf("%d\n",ans[n-=10]);
	go(1,0);
	return 0;
}
