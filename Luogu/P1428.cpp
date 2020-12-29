#include<cstdio>
using namespace std;
int n,a[101],b[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(a[j]<a[i])
			{
				++b[i];
			}
		}
		printf("%d ",b[i]);
	}
	return 0;
}
