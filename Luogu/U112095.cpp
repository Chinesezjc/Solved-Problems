//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,l,r,fib[92];
int A(int now)
{
	int ans=0;
	for(int i=91;i;--i)
	{
		while(now>fib[i])
		{
			now-=fib[i];
			ans+=fib[i-1];
		}
	}
	return ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	fib[0]=1;
	for(int i=1;i<=91;++i)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	cin>>n;
	while(n)
	{
		--n;
		cin>>l>>r;
		cout<<A(r+1)-A(l)<<endl;
	}
	return 0;
}

