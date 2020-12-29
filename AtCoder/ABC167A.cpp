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
string a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	a+=b[b.length()-1];
	if(a==b)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

