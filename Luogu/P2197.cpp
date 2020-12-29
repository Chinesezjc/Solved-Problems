//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,s,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			cin>>s;
			ans^=s;
		}
		cout<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}

