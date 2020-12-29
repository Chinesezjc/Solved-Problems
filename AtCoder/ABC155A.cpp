//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[3];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]==a[1]&&a[0]!=a[2])
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	if(a[1]==a[2]&&a[0]!=a[2])
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}

