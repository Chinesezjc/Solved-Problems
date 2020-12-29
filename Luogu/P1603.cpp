#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<iostream>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd*=xxx;
}
inline char rd(char &ddd)
{
	char tmp=getchar();
	while(tmp==' '||tmp=='\n')
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	return ddd=tmp;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
inline bool cmp(const int &A,const int &B)
{
	return A<B;
}
int n,num[7],i;
bool flag;
string x;
map<string,int>a;
signed main()
{
	a["a"]=1;
	a["both"]=4;
	a["first"]=1;
	a["second"]=4;
	a["third"]=9;
	a["one"]=1;
	a["two"]=4;
	a["three"]=9;
	a["four"]=16;
	a["five"]=25;
	a["six"]=36;
	a["seven"]=49;
	a["eight"]=64;
	a["nine"]=81;
	a["ten"]=0;
	a["eleven"]=21;
	a["twelve"]=44;
	a["thirteen"]=69;
	a["fourteen"]=96;
	a["fifteen"]=25;
	a["sixteen"]=56;
	a["seventeen"]=89;
	a["eighteen"]=24;
	a["nineteen"]=61;
	for(i=1;i<=6;++i)
	{
		cin>>x;
		if(a.find(x)!=a.end())
		{
			num[i]=a[x];
		}
	}
	sort(num,num+7,cmp);
	i=0;
	while(!num[i]&&i<=6)
	{
		++i;
	}
	if(i>6)
	{
		puts("0");
		return 0;
	}
	printf("%lld",num[i]);
	while(num[++i]<10&&i<=6)
	{
		printf("0%lld",num[i]);
	}
	while(i<=6)
	{
		printf("%lld",num[i++]);
	}
	return 0;
}

