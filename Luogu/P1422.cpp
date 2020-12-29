#include<cstdio>
using namespace std;
int in;
int main()
{
	scanf("%d",&in);
	if(in<=150)
	{
		printf("%.1lf",in*0.4463);
	}
	else
	if(in<=400)
	{
		printf("%.1lf",in*0.4663-3);
	}
	else
	{
		printf("%.1lf",in*0.5663-43);
	}
}
