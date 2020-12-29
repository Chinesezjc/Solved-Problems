//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[11],cho[5001],from[5001];
queue <int> in;
string M;
string get(int now)
{
	if(now==-1)
	{
		return "";
	}
	return get(from[now])+(char)('0'+cho[now]);
}
string s(int now)
{
	if(now==0)
	{
		return "";
	}
	return s(now/10)+(char)('0'+now%10);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	M=s(m);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0)
		{
			continue;
		}
		cho[a[i]%m]=a[i];
		from[a[i]%m]=-1;
		in.push(a[i]%m);
		if(a[i]%m==0&&a[i]>m)
		{
			cout<<a[i]<<endl;
			return 0;
		}
	}
	while(!in.empty())
	{
		for(int i=1;i<=n;++i)
		{
			int now=(in.front()*10+a[i])%m;
			if(now==0)
			{
				string ans=get(in.front())+(char)('0'+a[i]);
				if(ans!=M)
				{
					cout<<ans<<endl;
					return 0;
				}
				now+=m;
			}
			if(!from[now])
			{
				from[now]=in.front();
				cho[now]=a[i];
				in.push(now);
			}
		}
		in.pop();
	}
	return 0;
}

