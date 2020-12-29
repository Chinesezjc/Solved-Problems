//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int x,y,A,B,tmp;
void exgcd(int a,int b)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>A>>B;
	exgcd(A,B);
	x=(x%B+B)%B;
	cout<<x;
	return 0;
}

