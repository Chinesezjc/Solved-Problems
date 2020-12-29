//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,t,a[10001],x,b[51],cnt;
bool flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		for(int i=1;i<=n<<2;++i)
		{
			cin>>x;
			++a[x];
		}
		cnt=0;
		flag=true;
		for(int i=1;i<=10000;++i)
		{
			if(a[i]&1)
			{
				flag=false;
				a[i]=0;
			}
			else
			{
				a[i]>>=1;
				while(a[i])
				{
					--a[i];
					b[++cnt]=i;
				}
			}
		}
		for(int i=2,ans=b[1]*b[cnt];i<=cnt>>1&&flag;++i)
		{
			if(ans!=b[i]*b[cnt-i+1])
			{
				flag=false;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}

