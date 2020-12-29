#include<cstdio>
using namespace std;
int n;
char now;
int main()
{
	scanf("%d",&n);
	while(now!=EOF)
	{
		now=getchar();
		if('a'<=now&&now<='z')
		{
			now-='a';
			now+=n;
			now%=26;
			now+='a';
			putchar(now);
		}
	}
	return 0;
}
