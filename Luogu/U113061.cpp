//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int f(int x)
{
	if(x<10)
	{
		return x;
	}
	else
	{
		return x%10+f(x/10);
	}
}
int n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	int x=sqrt(n);
	for(int i=x;i>x-100000;--i)
	{
		if(i*i+i*f(i)==n)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}

