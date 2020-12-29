//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[21],l,r;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n&&a[i];++i,++l);
	for(int i=n;i>0&&a[i];--i,++r);
	if((l&1)||(r&1))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}

