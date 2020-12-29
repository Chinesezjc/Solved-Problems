#include<cstdio>
#include<cstdlib>
using namespace std;
int l,r,now;
bool s(int x)
{
	if(x>r)
	{
		exit(0);
	}
	for(int i=2;i*i<=x;++i)
	{
		if(!(x%i))
		{
			return false;
		}
	}
	return l<=x;
}
int main()
{
	scanf("%d%d",&l,&r);
	if(l<=2&&2<=r)
	{
		puts("2");
	}
	if(l<=3&&3<=r)
	{
		puts("3");
	}
	if(l<=5&&5<=r)
	{
		puts("5");
	}
	if(l<=7&&7<=r)
	{
		puts("7");
	}
	if(l<=11&&11<=r)
	{
		puts("11");
	}
	for(int i1=1;i1<=9;i1+=2)
	{
		for(int i2=0;i2<=9;++i2)
		{
			now=i1*101+i2*10;
			if(s(now))
			{
				printf("%d\n",now);
			}
		}
	}
	for(int i1=1;i1<=9;i1+=2)
	{
		for(int i2=0;i2<=9;++i2)
		{
			for(int i3=0;i3<=9;++i3)
			{
				now=i1*10001+i2*1010+i3*100;
				if(s(now))
				{
					printf("%d\n",now);
				}
			}
		}
	}
	for(int i1=1;i1<=9;i1+=2)
	{
		for(int i2=0;i2<=9;++i2)
		{
			for(int i3=0;i3<=9;++i3)
			{
				for(int i4=0;i4<=9;++i4)
				{
					now=i1*1000001+i2*100010+i3*10100+i4*1000;
					if(s(now))
					{
						printf("%d\n",now);
					}
				}
			}
		}
	}
	for(int i1=1;i1<=9;i1+=2)
	{
		for(int i2=0;i2<=9;++i2)
		{
			for(int i3=0;i3<=9;++i3)
			{
				for(int i4=0;i4<=9;++i4)
				{
					for(int i5=0;i5<=9;++i5)
					{
						now=i1*100000001+i2*10000010+i3*1000100+i4*101000+i5*10000;
						if(s(now))
						{
							printf("%d\n",now);
						}
					}
				}
			}
		}
	}
}
