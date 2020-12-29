//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a,b;
int ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	for(int i=0;i<a.length();++i)
	{
		for(int j=0;j<b.length();++j)
		{
			ans+=(a[i]-'0')*(b[j]-'0');
		}
	}
	cout<<ans;
	return 0;
}

