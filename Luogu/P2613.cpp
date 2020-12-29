//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 19260817
using namespace std;
int A,B,x,y;
char c;
int get()
{
	int tmp=0;
	c=getchar();
	while(!('0'<=c&&c<='9'))
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		tmp=(tmp<<3)+(tmp<<1)+(c^'0');
		tmp%=MOD;
		c=getchar();
	}
	return tmp;
}
void exgcd(int a,int b)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	swap(x,y);
	y=y-a/b*x;
}
signed main()
{
	A=get();
	B=get();
	std::ios::sync_with_stdio(false);
	if(B==0)
	{
		cout<<"Angry!";
		return 0;
	}
	exgcd(B,MOD);
	x=(x%MOD+MOD)%MOD;
	A*=x;
	A%=MOD;
	cout<<A;
	return 0;
}

