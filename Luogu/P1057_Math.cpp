//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,ans,a,b,has[31];
const int p[31]={0,1,2,3,2,5,2,7,2,3,2,11,2,13,2,3,2,17,2,19,2,3,2,23,2,5,2,3,2,29,2};
void s1(int l)
{
	if(l==1)
	{
		return;
	}
	++has[p[l]];
	s1(l/p[l]);
}
void s2(int l)
{
	if(l==1)
	{
		return;
	}
	--has[p[l]];
	s2(l/p[l]);
}
int C(int N,int M)
{
	for(int i=M;i>N;--i)
	{
		s1(i);
	}
	for(int i=M-N;i;--i)
	{
		s2(i);
	}
	int tmp=1;
	for(int i=2;i<=M;++i)
	{
		while(has[i])
		{
			--has[i];
			tmp*=i;
		}
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=m/n*n;i>=-m;i-=n)
	{
		if((m-i)&1)
		{
			continue;
		}
		b=(m-i)>>1;
		ans+=C(b,m);
	}
	cout<<ans;
	return 0;
}

