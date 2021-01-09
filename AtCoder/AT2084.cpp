//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
string s;
bool c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;++i)
	{
		if(s[i]=='C')
		{
			c=true;
		}
		if(s[i]=='F'&&c)
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}

