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
int n,m,a[100001],b[100001],ANS;
map <pair<int,int>,int> ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i]>>b[i];
		if(a[i]<b[i])
		{
			ans[make_pair(a[i],b[i])]|=1;
		}
		if(a[i]>b[i])
		{
			ans[make_pair(b[i],a[i])]|=2;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(ans[make_pair(a[i],b[i])]==3)
		{
			++ANS;
			ans[make_pair(a[i],b[i])]=0;
		}
	}
	cout<<ANS;
	return 0;
}

