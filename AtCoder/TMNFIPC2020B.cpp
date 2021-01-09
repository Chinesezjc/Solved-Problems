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
int a,v,b,w,t,dis;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>v>>b>>w>>t;
	dis=abs(a-b);
	if(v<=w||dis>t*(v-w))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}

