//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans[201]={0,0,3,5},k,cnt;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>k;
	cnt=3;
	while(ans[cnt]<=k)
	{
		++cnt;
		ans[cnt]=ans[cnt-1]+ans[cnt-2];
	}
	cout<<ans[cnt-1]<<' '<<ans[cnt-2]<<endl;
	return 0;
}

