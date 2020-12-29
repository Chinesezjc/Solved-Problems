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
int ans,alen,blen;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	alen=a.length();
	blen=b.length();
	for(int i=0;i<alen-1;++i)
	{
		for(int j=1;j<blen;++j)
		{
			if(a[i]==b[j]&&a[i+1]==b[j-1])
			{
				++ans;
			}
		}
	}
	cout<<(1<<ans);
	return 0;
}

