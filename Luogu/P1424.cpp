#include<cstdio>
using namespace std;
long long x,n,ans;
int main()
{
	scanf("%lld%lld",&x,&n);
	--x;
	n+=x;
	ans=n*250;
	if(n%7==6)
	{
		ans-=(n%7-5)*250;
	}
	if(x>5)
	{
		x=5;
	}
	ans-=x*250;
	ans-=n/7*500;
	printf("%lld",ans);
	return 0;
}
