//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string x,s[200001];
int cnt,n;
map <string,int> a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>x;
		if(a[x]==0)
		{
			s[++cnt]=x;
		}
		++a[x];
	}
	sort(s+1,s+1+cnt);
	int Max=0;
	for(int i=1;i<=cnt;++i)
	{
		Max=max(a[s[i]],Max);
	}
	for(int i=1;i<=cnt;++i)
	{
		if(a[s[i]]==Max)
		{
			cout<<s[i]<<endl;
		}
	}
	return 0;
}

