//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a,b,c,ans,l;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	while(n)
	{
		--n;
		cin>>a>>b>>c;
		ans=(m-1)/(a*b)*(b+c);
		l=ans/(b+c)*(a*b);
		while(l<m)
		{
			++ans;
			l+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}

