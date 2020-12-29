//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
char x;
string s,ans;
int len;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>x>>s;
	if(x!='-')
	{
		s=x+s;
	}
	else
	{
		cout<<x;
	}
	len=s.length();
	while(s[len-1]=='0')
	{
		--len;
	}
	for(int i=0;i<len;++i)
	{
		ans.push_back(s[len-i-1]);
	}
	cout<<ans;
	return 0;
}

