#include<cstdio>
using namespace std;
int a,b,c;
bool used[10];
int main()
{
	for(int i=192;i<=329;++i)
	{
		a=i;
		b=i<<1;
		c=(i<<1)+i;
		while(a>0)
		{
			used[a%10]=true;
			used[b%10]=true;
			used[c%10]=true;
			a/=10;
			b/=10;
			c/=10;
		}
		if(used[1]&&used[2]&&used[3]&&used[4]&&used[5]&&used[6]&&used[7]&&used[8]&&used[9])
		{
			printf("%d %d %d\n",i,i<<1,(i<<1)+i);
		}
		for(int j=1;j<=9;++j)
		{
			used[j]=false;
		}
	}
	return 0;
}
