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
int n;
string a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		a=(char)(n%26+'a')+a;
		n/=26;
	}
	cout<<a;
	return 0;
}

