//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int log_2[4096],T,a,b,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=2048;i;--i)
	{
		log_2[i]=INF;
	}
	for(int i=0;i<=11;++i)
	{
		log_2[1<<i]=i;
	}
	for(int i=2047;i;--i)
	{
		log_2[i]=min(log_2[i],log_2[i+1]);
	}
	cin>>T;
	while(T)
	{
		--T;
		cin>>a>>b>>c;
		cout<<a*b*c-1<<' '<<log_2[a]+log_2[b]+log_2[c]<<endl;
	}
	return 0;
}

