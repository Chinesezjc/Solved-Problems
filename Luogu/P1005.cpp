//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define maxnum 100000000
using namespace std;

struct bigint
{
    int num[10],str;
    
    bigint(void)
    {
        clear();
    }
    
    void clear()
    {
    	str=1;
        for(int i=0;i<10;++i)
        {
            num[i]=0;
        }
	}
    
    inline void work(void)
    {
        while(num[str-1]==0&&str>1)
        {
            --str;
        }
    }
    
    void read(string a)
    {
    	clear();
        str=0;
        int len=a.length();
        for(int i=0;i<len/2;++i)
        {
        	swap(a[i],a[len-i-1]);
        }
        for(int i=0;i<len;i+=8)
        {
            for(int j=1,k=0;k<8&&i+k<len;j*=10,++k)
            {
                if(a[i+k]>='0'&&a[i+k]<='9')
                {
                	num[i/8]+=(a[i+k]-'0')*j;
				}
			}
            ++str;
        }
    	work();
    }
    
    void write(void)
    {
        cout<<num[str-1];
        for(int i=str-2;i>=0;--i)
        {
        	for(int j=maxnum/10;j>num[i];j/=10)
        	{
        		cout<<'0';
			}
            cout<<num[i];
        }
    }
    
    bigint operator+(const bigint x)const
    {
        bigint tmp;
        tmp.str=str>x.str?str:x.str;
        for(int i=0;i<tmp.str;++i)
        {
            tmp.num[i]+=num[i]+x.num[i];
            tmp.num[i+1]+=tmp.num[i]/maxnum;
            tmp.num[i]%=maxnum;
        }
        if(tmp.num[tmp.str]>0)
        {
            ++tmp.str;
        }
        return tmp;
    }
    
    bigint operator<<(const int x)const
    {
    	bigint tmp;
		for(int i=0;i<str;++i)
		{
			tmp.num[i]+=num[i]<<x;
			tmp.num[i+1]+=tmp.num[i]/maxnum;
			tmp.num[i]%=maxnum;
		}
		tmp.str=str+2;
		tmp.work();
		return tmp;
	}
    
    void operator+=(const bigint x)
    {
        *this=*this+x;
    }
    
    bool operator<(const bigint x)const
    {
        if(str<x.str)
        {
            return true;
        }
        if(str==x.str)
        {
            for(int i=str-1;i>=0;i--)
            {
                if(num[i]<x.num[i])
                {
                    return true;
                }
                if(num[i]>x.num[i])
                {
                    return false;
                }
            }
        }
        return false;
    }
};
bigint max(const bigint &A,const bigint &B)
{
	return B<A?A:B;
}
bigint a[81],dp[81][81],ans;
int n,m;
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>s;
			dp[j][j].read(s);
		}
		for(int k=1;k<=m;++k)
		{
			for(int j=1;j+k<=m;++j)
			{
				dp[j][j+k]=max((dp[j][j+k-1]<<1)+dp[j+k][j+k],(dp[j+1][j+k]<<1)+dp[j][j]);
			}
		}
		ans+=dp[1][m]<<1;
	}
	ans.write();
	return 0;
}

