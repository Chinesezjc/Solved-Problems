//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x1,x2,y_1,y2,x,y;
struct N{
	int d1,d2;
}a[100001];
bool cmp(const N &A,const N &B)
{
	return A.d1<B.d1;
}
int S(int X)
{
	return X*X;
}
int D(int &X1,int &Y1,int &X2,int &Y2)
{
	return S(X1-X2)+S(Y1-Y2);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>x1>>y_1>>x2>>y2>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x>>y;
		a[i].d1=D(x1,y_1,x,y);
		a[i].d2=D(x2,y2,x,y);
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[n].d1,i=n,MAX=0;
	while(i>0)
	{
		--i;
		MAX=max(MAX,a[i+1].d2);
		ans=min(ans,MAX+a[i].d1);
	}
	cout<<ans;
	return 0;
}

