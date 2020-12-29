#include<cstdio>
using namespace std;
int a,b,max,maxn;
int main()
{
	for(int i=1;i<=7;++i)
	{
		scanf("%d%d",&a,&b);
		if(a+b>max)
		{
			max=a+b;
			maxn=i;
		}
	}
	if(max>8)
	{
		printf("%d",maxn);
	}
	else
	{
		puts("0");
	}
	return 0;
}
