//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string A,B,a[7],b[7];
map<string,bool>came;
int n,ans=INF,x;
void dfs(string now,int cho)
{
	if(came[now])
	{
		return;
	}
	came[now]=true;
	if(ans<=cho)
	{
		return;
	}
	if(now==B)
	{
		ans=cho;
		return;
	}
	if(cho==x)
	{
		return;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=now.find(a[i],0);j<now.length();j=now.find(a[i],j+1))
		{
			dfs(now.substr(0,j)+b[i]+now.substr(j+a[i].length(),now.length()-j-a[i].length()),cho+1);
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>A>>B;
	do
	{
		++n;
	}
	while(cin>>a[n]>>b[n]);
	--n;
	while(x<10)
	{
		++x;
		came.clear();
		dfs(A,0);
		if(ans<INF)
		{
			break;
		}
	}
	if(ans>=INF)
	{
		cout<<"NO ANSWER!"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}

