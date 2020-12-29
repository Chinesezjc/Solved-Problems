#include<cstdio>
using namespace std;
int a,b,c,x,y,z;
bool used[10],flag;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	for(int i=1;i<=999;++i)
	{
		a=i*x;
		b=i*y;
		c=i*z;
		for(int j=1;j<=3;++j)
		{
			used[a%10]=true;
			used[b%10]=true;
			used[c%10]=true;
			a/=10;
			b/=10;
			c/=10;
		}
		if(a==0&&b==0&&c==0&&used[1]&&used[2]&&used[3]&&used[4]&&used[5]&&used[6]&&used[7]&&used[8]&&used[9])
		{
			printf("%d %d %d\n",i*x,i*y,i*z);
			flag=true;
		}
		for(int j=1;j<=9;++j)
		{
			used[j]=false;
		}
	}
	if(!flag)
	{
		puts("No!!!");
	}
	return 0;
}
