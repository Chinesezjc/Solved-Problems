//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int work(int n,int i,int j)
{
	if(i==1)
	{
		return j;
	}
	if(j==n)
	{
		return n-1+i;
	}
	if(i==n)
	{
		return 3*(n-1)-j+2;
	}
	if(j==1)
	{
		return 4*(n-1)-i+2;
	}
	return work(n-2,i-1,j-1)+4*(n-1);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	int n,i,j;
	cin>>n>>i>>j;
	cout<<work(n,i,j);
	return 0;
}

