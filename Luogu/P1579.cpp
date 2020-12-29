#include<cstdio>
using namespace std;
int them[10000],n,cnt;
bool is[20001];
int main()
{
	is[1]=true;
	for(int i=3;i<=20000;i+=2)
	{
		for(int j=i*3;j<=20000;j+=i*2)
		{
			is[j]=true;
		}
	}
	for(int i=2;i<=20000;i+=2)
	{
		is[i]=true;
	}
	scanf("%d",&n);
	if(!is[n-4])
	{
		printf("2 2 %d",n-4);
		return 0;
	}
	for(int i=3;i<=n-2-i;i+=2)
	{
		if(!is[i]&&!is[n-2-i])
		{
			printf("2 %d %d",i,n-2-i);
			return 0;
		}
	}
	for(int i=3;i<=((n-i)>>1)+1;i+=2)
	{
		if(is[i])
		{
			continue;
		}
		for(int j=i;j<=n-i-j;j+=2)
		{
			if(!is[j]&&!is[n-i-j])
			{
				printf("%d %d %d",i,j,n-i-j);
				return 0;
			}
		}
	}
}
