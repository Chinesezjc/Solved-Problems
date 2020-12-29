//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p[5761456],cnt;
bool s[50000001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	if(n<2)
	{
		cout<<0;
		return 0;
	}
	p[++cnt]=2;
	for(int i=3;i<=n;i+=2)
	{
		if(!s[i>>1])
		{
			p[++cnt]=i;
		}
		for(int j=2;j<=cnt;++j)
		{
			if(i*p[j]>n)
			{
				break;
			}
			s[i*p[j]>>1]=true;
			if(!(i%p[j]))
			{
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

