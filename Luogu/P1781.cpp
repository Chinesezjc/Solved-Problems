#include<cstdio>
#include<string>
#include<iostream>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
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
	ddd*=xxx;
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
	if(A.length()==B.length())
	{
		return A>B;
	}
	else
	{
		return A.length()>B.length();
	}
}
int n,a;
string num,ans;
signed main()
{
	rd(n);
	cin>>ans;
	a=1;
	for(int i=2;i<=n;++i)
	{
		cin>>num;
		if(cmp(num,ans))
		{
			ans=num;
			a=i;
		}
	}
	cout<<a<<endl<<ans;
	return 0;
}

