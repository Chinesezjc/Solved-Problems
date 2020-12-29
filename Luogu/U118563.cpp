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
int n,m,a,b,c;
vector <pair<int,int> > s[10001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		s[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=n;++i)
	{
		cout<<i<<':'<<endl;
		for(int j=s[i].size()-1;j>=0;--j)
		{
			cout<<s[i][j].first<<' '<<s[i][j].second<<endl;
		}
	}
	return 0;
}

