#include<cstdio>
#define f(i,j) (a[i]-'0')*j
using namespace std;
char a[15];
int right;
int main()
{
	scanf("%s",a);
	right=(f(0,1)+f(2,2)+f(3,3)+f(4,4)+f(6,5)+f(7,6)+f(8,7)+f(9,8)+f(10,9))%11;
	if(right==10)
	{
		if('X'==a[12])
		{
			puts("Right");
		}
		else
		{
			a[12]='X';
			puts(a);
		}
	}
	else
	{
		if(right==a[12]-'0')
		{
			puts("Right");
		}
		else
		{
			a[12]=right+'0';
			puts(a);
		}
	}
	return 0;
}
