//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a[1000001],l=1,ans;
map <int,int> last;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		l=1;
		ans=0;
		last.clear();
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(last[a[i]]>=l)
			{
				l=last[a[i]]+1;
			}
			last[a[i]]=i;
			ans=max(i-l+1,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}

