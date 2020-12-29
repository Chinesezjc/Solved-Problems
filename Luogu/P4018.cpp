//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int T,n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>T;
	while(T)
	{
		--T;
		cin>>n;
		cout<<(n%6?"October wins!":"Roy wins!")<<endl;
	}
	return 0;
}

