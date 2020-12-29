//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>x;
		if(x&1)
		{
			continue;
		}
		else
		{
			if(x%3==0||x%5==0)
			{
				continue;
			}
			else
			{
				cout<<"DENIED"<<endl;
				return 0;
			}
		}
	}
	cout<<"APPROVED"<<endl;
	return 0;
}

