#include<cstdio>
using namespace std;
int ans[1002],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1;i+=2)
	{
		++ans[i];
		for(int j=1;j<=i/2;++j)
		{
			ans[i]+=ans[j];
		}
		ans[i-1]=ans[i];
	}
	printf("%d",ans[n]);
	return 0;
}
