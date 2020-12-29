#include<cstdio>
#include<cstring>
using namespace std;
char name[2][7];
int sum[2];
int main()
{
	scanf("%s%s",name[0],name[1]);
	for(int i=0;i<2;++i)
	{
		sum[i]=1;
		for(int j=0;j<strlen(name[i]);++j)
		{
			sum[i]*=name[i][j]-'A'+1;
		}
		sum[i]%=47;
	}
	if(sum[0]==sum[1])
	{
		puts("GO");
	}
	else
	{
		puts("STAY");
	}
	return 0;
}
