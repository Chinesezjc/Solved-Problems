//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
double n,ans[501];
int find()
{
	int l=1,r=500;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(ans[mid]<=n)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return l;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=500;++i)
	{
		ans[i]=ans[i-1]+1.0/(i+1);
	}
	while(cin>>n)
	{
		if(n==0)
		{
			return 0;
		}
		int ANS=find();
		cout<<"TH"<<ANS<<endl;
	}
	return 0;
}

