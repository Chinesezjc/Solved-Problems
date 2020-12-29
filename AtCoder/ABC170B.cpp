//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	if(b&1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	b>>=1;
	b-=a;
	if(0<=b&&b<=a)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

