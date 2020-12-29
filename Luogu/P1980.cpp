#include<cstdio>
using namespace std;
int n,x,ans,l,m,r;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i*=10)
	{
		l=n/(i*10);
		m=n%(i*10)/i;
		r=n%i;
		if(x)
		{
			if(m>x)
			{
				ans+=(l+1)*i;
			}
			if(m==x)
			{
				ans+=l*i+r+1;
			}
			if(m<x)
			{
				ans+=l*i;
			}
		}
		else
		{
			ans+=m?l*i:(l-1)*i+r+1;
		}
	}
	printf("%d",ans);
	return 0;
}
