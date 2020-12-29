//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,s[20001];
int SG(int a,int b)
{
	int sum=(a-1)|(b-1);
	for(int i=0;i<60;++i)
	{
		if(!(sum&(1<<i)))
		{
			return i;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>s[i];
		}
		int ans=0;
		for(int i=1;i<=n;i+=2)
		{
			ans^=SG(s[i],s[i+1]);
		}
		if(ans==0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

