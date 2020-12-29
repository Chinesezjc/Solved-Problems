#include<cstdio>
#include<iostream>
#define mid ((x+y)/2)
using namespace std;
struct NUM{
	int v,t;
	bool operator > (const NUM tmp)
	{
		return v>tmp.v;
	}
}num[1000001],xx[1000001];
int n,sum,cnt1,cnt2,has1,has2;
long long ans;
void sort(int x,int y)
{
	if(x==y)
	{
		return;
	}
	if(x+1==y)
	{
		if(num[x]>num[y])
		{
			ans+=n-num[y].t+num[x].t;
		}
		else
		{
			swap(num[x],num[y]);
		}
		return;
	}
	sort(x,mid);
	sort(mid+1,y);
	cnt1=x;
	cnt2=mid+1;
	has1=mid-x+1;
	has2=y-mid;
	sum=(mid+y+1)*has2/2;
	for(int i=x;i<=y;++i)
	{
		xx[i]=num[i];
	}
	while(cnt1<=mid&&cnt2<=y)
	{
		if(xx[cnt1]>xx[cnt2])
		{
			ans+=has2*n+has2*xx[cnt1].t-sum;
			num[y-has1-has2+1]=xx[cnt1];
			++cnt1;
			--has1;
		}
		else
		{
			sum-=xx[cnt2].t;
			num[y-has1-has2+1]=xx[cnt2];
			++cnt2;
			--has2;
		}
	}
	while(cnt1<=mid)
	{
		num[y-has1-has2+1]=xx[cnt1];
		++cnt1;
		--has1;
	}
	while(cnt2<=y)
	{
		num[y-has1-has2+1]=xx[cnt2];
		++cnt2;
		--has2;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num[i].v);
		num[i].t=i;
	}
	sort(1,n);
	printf("%lld",ans);
	return 0;
}
