//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[500001],b,c,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		ans^=a[i];
	}
	if(ans)
	{
		for(int i=1;i<=n;++i)
		{
			if((ans^a[i])<a[i])
			{
				cout<<a[i]-(ans^a[i])<<' '<<i<<endl;
				a[i]=ans^a[i];
				break;
			}
		}
		for(int i=1;i<=n;++i)
		{
			cout<<a[i]<<' ';
		}
	}
	else
	{
		cout<<"lose";
	}
	return 0;
}

