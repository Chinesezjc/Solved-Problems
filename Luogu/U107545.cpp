//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define maxnum 100000000
using namespace std;
int n;
struct High_Accuracy_Algorithm
{
    int num[10],n;
    bool P_or_N;
    
    High_Accuracy_Algorithm()
    {
    	clear();
    }
    
    void clear()
    {
    	n=1;
        P_or_N=false;
        for(int i=0;i<10;++i)
        {
            num[i]=0;
        }
	}
    
    inline void work()
    {
        while(num[n-1]==0&&n>1)
        {
            --n;
        }
        if(n==1&&num[0]==0)
        {
            P_or_N=false;
        }
    }
    void write()
    {
        if(P_or_N)
        {
            cout<<'-';
        }
        cout<<num[n-1];
        for(int i=n-2;i>=0;--i)
        {
        	if(num[i]==0)
        	{
        		cout<<"00000000";
        		continue;
			}
        	for(int j=maxnum/10;j>num[i];j/=10)
        	{
        		cout<<'0';
			}
            cout<<num[i];
        }
    }
    High_Accuracy_Algorithm operator+(const High_Accuracy_Algorithm x)const
    {
        High_Accuracy_Algorithm tmp;
        tmp.n=n>x.n?n:x.n;
        for(int i=0;i<tmp.n;++i)
        {
            tmp.num[i]+=num[i]+x.num[i];
            tmp.num[i+1]+=tmp.num[i]/maxnum;
            tmp.num[i]%=maxnum;
        }
        if(tmp.num[tmp.n]>0)
        {
            ++tmp.n;
        }
        return tmp;
    }
}a[80][80];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	a[1][1].num[0]=1;
	for(int i=2;i<=n+1;++i)
	{
		for(int j=1;j<=i;++j)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	cout<<"(a+b)^"<<n<<"=";
	if(n==0)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n+1;++i)
	{
		if(i!=1)
		{
			cout<<'+';
		}
		if(i!=1&&i!=n+1)
		{
			a[n+1][i].write();
		}
		//a^(n-i+1),b^(i-1)
		if(n-i+1>0)
		{
			cout<<'a';
			if(n-i+1>1)
			{
				cout<<'^'<<n-i+1;
			}
		}
		if(i-1>0)
		{
			cout<<'b';
			if(i-1>1)
			{
				cout<<'^'<<i-1;
			}
		}
	}
	return 0;
}

