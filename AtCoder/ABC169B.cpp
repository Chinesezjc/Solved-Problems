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
#define INF 1000000000000000000
using namespace std;
int ans=1,a,n;
bool boom;
int mul(int A,int B)
{
	int tmp=0;
	while(B)
	{
		if(A>INF||tmp>INF)
		{
			return boom=true;
		}
		if(B&1)
		{
			tmp+=A;
		}
		B>>=1;
		A<<=1;
	}
	if(tmp>INF)
	{
		return boom=true;
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		ans=mul(ans,a);
	}
	if(boom&&ans!=0)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}

