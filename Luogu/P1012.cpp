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
inline bool cmp(const string &A,const string &B)
{
	return A+B>B+A;
}
int n;
string num[21];
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		cin>>num[i];
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		cout<<num[i];
	}
	return 0;
}

