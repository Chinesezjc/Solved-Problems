#include<cstdio>
using namespace std;
double x,n;
int i;
int main()
{
	scanf("%lf",&x);
	for(i=1,n=2,x-=n;x>0;++i,n*=0.98,x-=n);
	printf("%d",i);
	return 0;
}
