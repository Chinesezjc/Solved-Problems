//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,l,a,small,big;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>l>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		small=max(small,min(a,l+1-a));
		big=max(big,max(a,l+1-a));
	}
	cout<<small<<' '<<big<<endl;
	return 0;
}

