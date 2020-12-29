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
int n,a[200001],b[200001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	if(n&1)
	{
		cout<<b[(n+1)>>1]-a[(n+1)>>1]+1<<endl;
	}
	else
	{
		int l=a[n>>1]+a[(n>>1)+1],r=b[n>>1]+b[(n>>1)+1];
		cout<<r-l+1<<endl;
	}
	return 0;
}

