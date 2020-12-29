//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
int n,Front,Behind,Left,Right,Up,Down,front,behind,left,right,up,down,ans;
bool dfs(int now)
{
	if(now==1)
	{
		for(int i=1;i<=4;++i)
		{
			int tmp=left;
			left=front;
			front=right;
			right=behind;
			behind=tmp;
			if(dfs(2))
			{
				return true;
			}
		}
	}
	if(now==2)
	{
		for(int i=1;i<=4;++i)
		{
			int tmp=up;
			up=right;
			right=down;
			down=left;
			left=tmp;
			if(dfs(3))
			{
				return true;
			}
		}
	}
	if(now==3)
	{
		for(int i=1;i<=4;++i)
		{
			int tmp=front;
			front=up;
			up=behind;
			behind=down;
			down=tmp;
			if(dfs(4))
			{
				return true;
			}
		}
	}
	if(now==4)
	{
		if(up==Up&&down==Down&&left==Left&&right==Right&&front==Front&&behind==Behind)
		{
			++ans;
			return true;
		}
		return false;
	}
	return false;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin>>n;
	std::cin>>Front>>Behind>>Left>>Right>>Up>>Down;
	while(--n)
	{
		std::cin>>front>>behind>>left>>right>>up>>down;
		dfs(1);
	}
	std::cout<<ans;
	return 0;
}

