#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#define int long long
using namespace std;
string a;
int W,L,len;
char tmp;
signed main()
{
	tmp=getchar();
	while(tmp!='E')
	{
		a.push_back(tmp);
		tmp=getchar();
	}
	len=a.length();
	W=L=0;
	for(int i=0;i<len;++i)
	{
		if(a[i]=='W')
		{
			++W;
		}
		if(a[i]=='L')
		{
			++L;
		}
		if((W>10||L>10)&&abs(W-L)>=2)
		{
			printf("%lld:%lld\n",W,L);
			W=L=0;
		}
	}
	printf("%lld:%lld\n",W,L);
	puts("");
	W=L=0;
	for(int i=0;i<len;++i)
	{
		if(a[i]=='W')
		{
			++W;
		}
		if(a[i]=='L')
		{
			++L;
		}
		if((W>20||L>20)&&abs(W-L)>=2)
		{
			printf("%lld:%lld\n",W,L);
			W=L=0;
		}
	}
	printf("%lld:%lld\n",W,L);
	return 0;
}
