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
int a,b,c,n,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>c>>n;
	ans+=min(a,n);
	n-=a+b;
	n=max(n,0ll);
	ans-=min(c,n);
	cout<<ans<<endl;
	return 0;
}

