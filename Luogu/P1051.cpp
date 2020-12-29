#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
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
int n,sum,got,b,c,f,Max;
string ans,a;
char d,e;
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b>>c>>d>>e>>f;
		got=0;
		if(b>80&&f>0)
		{
			got+=8000;
		}
		if(b>85&&c>80)
		{
			got+=4000;
		}
		if(b>90)
		{
			got+=2000;
		}
		if(b>85&&e=='Y')
		{
			got+=1000;
		}
		if(c>80&&d=='Y')
		{
			got+=850;
		}
		if(got>Max)
		{
			Max=got;
			ans=a;
		}
		sum+=got;
	}
	cout<<ans<<endl<<Max<<endl<<sum;
	return 0;
}

