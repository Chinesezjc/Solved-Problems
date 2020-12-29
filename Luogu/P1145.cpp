//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k;
bool dfs(int now)
{
	int left=n,name=(now-1)%left;
	while(left>k)
	{
		if(name>=k)
		{
			--left;
			name=(name+now-1)%left;
		}
		else
		{
			return false;
		}
	}
	return true;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>k;
	n=k<<1;
	for(int i=1;i<=100000000;++i)
	{
		if(dfs(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

