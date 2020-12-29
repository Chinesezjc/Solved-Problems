//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,c;
bool ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>c;
	while(c)
	{
		--c;
		cin>>a>>b;
		if(a<b)
		{
			swap(a,b);
		}
		ans=true;
		while(true)
		{
			if(!(a%b))
			{
				cout<<(ans?"Stan wins":"Ollie wins")<<endl;
				break;
			}
			a-=b;
			swap(a,b);
			if(a<b)
			{
				cout<<(ans?"Stan wins":"Ollie wins")<<endl;
				break;
			}
			ans=!ans;
		}
	}
	return 0;
}

