//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a;
int len;
bool check()
{
	for(int i=0;i<len-i-1;++i)
	{
		if(a[i]!=a[len-i-1])
		{
			return false;
		}
	}
	return true;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a;
	len=a.length();
	while(true)
	{
		if(len&1||!check())
		{
			cout<<len<<endl;
			return 0;
		}
		len>>=1;
	}
	return 0;
}

