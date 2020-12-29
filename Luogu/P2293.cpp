//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
//This code is made from Chinese_zjc_.
//This header file is about High Accuracy Algorithm.
//It used for calculating very big number such as addition,subtraction,multiplication,disvision and so on.

#include<string>
#include<iostream>

#define int long long
#define maxnum 100000000

#define HAA High_Accuracy_Algorithm
//You can use the "HAA" like "High_Accuracy_Algorithm".
//They are the same.

char NUM[2][2]={"0","1"};

using namespace std;

struct High_Accuracy_Algorithm
{
	int num[10000],n;
	bool P_or_N;
	
	inline High_Accuracy_Algorithm()
	{
		clear();
	}
	
	inline void clear()
	{
		n=1;
		P_or_N=false;
		for(int i=0;i<10000;++i)
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
	
	inline void operator =(string a)
	{
		n=0;
		int len=a.length();
		if(a[0]=='-')
		{
			P_or_N=true;
			for(int i=0;i<(len>>1)+1;++i)
			{
				swap(a[i],a[len-i]);
			}
			for(int i=1;i<len-1;i+=8)
			{
				for(int j=1,k=0;k<8&&i+k<len-1;j*=10,++k)
				{
					num[i>>3]+=(a[i+k]-'0')*j;
				}
				++n;
			}
		}
		else
		{
			for(int i=0;i<len>>1;++i)
			{
				swap(a[i],a[len-i-1]);
			}
			for(int i=0;i<len;i+=8)
			{
				for(int j=1,k=0;k<8&&i+k<len;j*=10,++k)
				{
					num[i>>3]+=(a[i+k]-'0')*j;
				}
				++n;
			}
		}
		work();
	}
	
	inline int operator[](const int x)const
	{
		return num[x];
	}
	
	inline int length(const int x)const
	{
		return n;
	}
	
	inline High_Accuracy_Algorithm operator<<(const int x)const
	{
		High_Accuracy_Algorithm tmp;
		tmp.n=n+x;
		tmp.P_or_N=P_or_N;
		for(int i=n-1;i>=0;--i)
		{
			tmp.num[i+x]=num[i];
		}
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator>>(const int x)const
	{
		High_Accuracy_Algorithm tmp;
		if(n-x<1)
		{
			return tmp;
		}
		tmp.n=n-x;
		tmp.P_or_N=P_or_N;
		for(int i=tmp.n-1;i>=0;--i)
		{
			tmp.num[i]=num[i+x];
		}
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator+(const High_Accuracy_Algorithm x)const
	{
		if(P_or_N&&!x.P_or_N)
		{
			return x-(-*this);
		}
		if(!P_or_N&&x.P_or_N)
		{
			return *this-(-x);
		}
		High_Accuracy_Algorithm tmp;
		if(P_or_N&&x.P_or_N)
		{
			tmp.P_or_N=true;
		}
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
	
	inline High_Accuracy_Algorithm operator+(const int x)const
	{
		if(P_or_N)
		{
			return -(-*this-x);
		}
		if(x<0)
		{
			return *this-(-x);
		}
		High_Accuracy_Algorithm tmp=*this;
		tmp.num[0]+=x;
		for(int i=0;tmp.num[i]>=maxnum;++i)
		{
			tmp.num[i]-=maxnum;
			++tmp.num[i+1];
		}
		++tmp.n;
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator-(const High_Accuracy_Algorithm x)const
	{
		if(x>*this)
		{
			return -(x-*this);
		}
		if(x.P_or_N&&!P_or_N)
		{
			return *this+(-x);
		}
		if(!x.P_or_N&&P_or_N)
		{
			return -((-*this)+x);
		}
		High_Accuracy_Algorithm tmp;
		if(x.P_or_N&&P_or_N)
		{
			if(x<*this)
			{
				return (-x)-(-*this);
			}
			tmp.P_or_N=true;
		}
		tmp.n=n;
		tmp.num[0]=num[0]-x.num[0];
		for(int i=1;i<tmp.n;++i)
		{
			tmp.num[i]=num[i]-x.num[i];
			if(tmp.num[i-1]<0)
			{
				tmp.num[i-1]+=maxnum;
				--tmp.num[i];
			}
		}
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator-(const int x)const
	{
		if(P_or_N)
		{
			return -(-*this+x);
		}
		if(x<0)
		{
			return *this+(-x);
		}
		if(*this<x)
		{
			High_Accuracy_Algorithm tmp;
			tmp=x;
			return *this-tmp;
		}
		High_Accuracy_Algorithm tmp=*this;
		tmp.num[0]-=x;
		for(int i=0;tmp.num[i]<0&&tmp.num[i+1]>0;++i)
		{
			tmp.num[i]+=maxnum;
			--tmp.num[i+1];
		}
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator*(const High_Accuracy_Algorithm x)const
	{
		High_Accuracy_Algorithm tmp;
		if(P_or_N^x.P_or_N)
		{
			tmp.P_or_N=true;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<x.n;++j)
			{
				tmp.num[i+j]+=num[i]*x.num[j];
				if(tmp.num[i+j]>=maxnum)
				{
					tmp.num[i+j+1]+=tmp.num[i+j]/maxnum;
					tmp.num[i+j]%=maxnum;
				}
			}
		}
		tmp.n=n+x.n;
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator*(const int x)const
	{
		High_Accuracy_Algorithm tmp;
		if(P_or_N^(x<0))
		{
			tmp.P_or_N=true;
		}
		for(int i=0;i<n;++i)
		{
			tmp.num[i]+=x*num[i];
			tmp.num[i+1]+=tmp.num[i]/maxnum;
			tmp.num[i]%=maxnum;
		}
		tmp.n=n+2;
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator/(const High_Accuracy_Algorithm x)const
	{
		High_Accuracy_Algorithm sum,now,tmp,l[27];
		l[0]=x;
		tmp.n=n;
		for(int i=1;i<=26;++i)
		{
			l[i]=l[i-1]*2;
		}
		for(int i=n-1;i>=0;--i)
		{
			sum<<=1;
			sum.num[0]=num[i];
			for(int j=26;j>=0;--j)
			{
				if(l[j]<=sum)
				{
					sum-=l[j];
					tmp.num[i]+=1<<j;
				}
			}
		}
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator/(const int x)const
	{
		High_Accuracy_Algorithm tmp=*this;
		if((P_or_N^x)<0)
		{
			tmp.P_or_N=true;
		}
		else
		{
			tmp.P_or_N=false;
		}
		for(int i=tmp.n-1;i>0;--i)
		{
			tmp.num[i-1]+=tmp.num[i]%(x<0?-x:x)*maxnum;
			tmp.num[i]/=(x<0?-x:x);
		}
		tmp.num[0]/=(x<0?-x:x);
		tmp.work();
		return tmp;
	}
	
	inline High_Accuracy_Algorithm operator%(const High_Accuracy_Algorithm x)const
	{
		return *this-*this/x*x;
	}
	
	inline int operator%(const int x)const
	{
		HAA tmp=*this-*this/x*x;
		return tmp.num[1]*maxnum+tmp.num[0];
	}
	
	inline friend High_Accuracy_Algorithm absolute_value(const High_Accuracy_Algorithm x)
	{
		High_Accuracy_Algorithm tmp=x;
		tmp.P_or_N=false;
		return tmp;
	}
	
	inline friend High_Accuracy_Algorithm power(High_Accuracy_Algorithm base,High_Accuracy_Algorithm index)
	{
		High_Accuracy_Algorithm tmp,ans=base,now=index;
		tmp="1";
		do
		{
			if(now.num[0]&1)
			{
				tmp*=ans;
			}
			now/=2;
			ans*=ans;
		}
		while(index>0);
		return tmp;
	}
	
	inline friend High_Accuracy_Algorithm power(High_Accuracy_Algorithm base,int index)
	{
		High_Accuracy_Algorithm tmp,ans=base;
		tmp="1";
		while(index>0)
		{
			if(index&1)
			{
				tmp*=ans;
			}
			index>>=1;
			ans*=ans;
		}
		return tmp;
	}
	
	inline friend High_Accuracy_Algorithm radical_sign(const High_Accuracy_Algorithm x,const int index)
	{
		if(x-x==x)
		{
			return x;
		}
		High_Accuracy_Algorithm r,l,mid,total;
		total="100000000";
		r=power(total,x.n/index+1);
		l=1;
		while(l<r)
		{
			mid=(l+r+1)/2;
			total=power(mid,index);
			if(total<=x)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		return l;
	}
	
//	inline friend High_Accuracy_Algorithm logarithm()
//	{
//	}
	
	inline void operator+=(const High_Accuracy_Algorithm x)
	{
		*this=*this+x;
	}
	
	inline void operator-=(const High_Accuracy_Algorithm x)
	{
		*this=*this-x;
	}
	
	inline void operator*=(const High_Accuracy_Algorithm x)
	{
		*this=*this*x;
	}
	
	inline void operator/=(const High_Accuracy_Algorithm x)
	{
		*this=*this/x;
	}
	
	inline void operator/=(const int x)
	{
		*this=*this/x;
	}
	
	inline void operator<<=(const int x)
	{
		*this=*this<<x;
	}
	
	inline void operator>>=(const int x)
	{
		*this=*this>>x;
	}
	
	inline void operator++(void)
	{
		High_Accuracy_Algorithm tmp;
		tmp.num[0]=1;
		*this+=tmp;
	}
	
	inline void operator--(void)
	{
		High_Accuracy_Algorithm tmp;
		tmp.num[0]=1;
		*this-=tmp;
	}
	
	inline High_Accuracy_Algorithm operator-(void)const
	{
		High_Accuracy_Algorithm tmp=*this;
		tmp.P_or_N=!tmp.P_or_N;
		return tmp;
	}
	
	inline bool operator>(const High_Accuracy_Algorithm x)const
	{
		if(!P_or_N&&x.P_or_N)
		{
			return true;
		}
		if(P_or_N&&!x.P_or_N)
		{
			return false;
		}
		if(P_or_N&&x.P_or_N)
		{
			High_Accuracy_Algorithm a=*this,b=x;
			a.P_or_N=false;
			b.P_or_N=false;
			return a<b;
		}
		if(n>x.n)
		{
			return true;
		}
		if(n==x.n)
		{
			for(int i=n-1;i>=0;--i)
			{
				if(num[i]>x.num[i])
				{
					return true;
				}
				if(num[i]<x.num[i])
				{
					return false;
				}
			}
		}
		return false;
	}
	
	inline bool operator>(const int x)const
	{
		if(P_or_N)
		{
			if(x<0)
			{
				return -*this<-x;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(x<0)
			{
				return true;
			}
		}
		int a=x;
		for(int i=0;i<n;++i)
		{
			if(num[i]>a)
			{
				return true;
			}
			a/=maxnum;
		}
		return false;
	}
	
	inline bool operator<(const High_Accuracy_Algorithm x)const
	{
		if(!P_or_N&&x.P_or_N)
		{
			return false;
		}
		if(P_or_N&&!x.P_or_N)
		{
			return true;
		}
		if(P_or_N&&x.P_or_N)
		{
			High_Accuracy_Algorithm a=*this,b=x;
			a.P_or_N=false;
			b.P_or_N=false;
			return a>b;
		}
		if(n<x.n)
		{
			return true;
		}
		if(n==x.n)
		{
			for(int i=n-1;i>=0;i--)
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
	
	inline bool operator<(const int x)const
	{
		if(P_or_N)
		{
			if(x<0)
			{
				return -*this>-x;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if(x<0)
			{
				return false;
			}
		}
		int a=x;
		for(int i=0;i<n;++i)
		{
			if(num[i]>a)
			{
				return false;
			}
			a/=maxnum;
		}
		return true;
	}
	
	inline bool operator==(const High_Accuracy_Algorithm x)const
	{
		if(P_or_N!=x.P_or_N)
		{
			return false;
		}
		if(n!=x.n)
		{
			return false;
		}
		for(int i=0;i<n;++i)
		{
			if(num[i]!=x.num[i])
			{
				return false;
			}
		}
		return true;
	}
	
	inline bool operator!=(const High_Accuracy_Algorithm x)const
	{
		return !(*this==x);
	}
	
	inline bool operator<=(const High_Accuracy_Algorithm x)const
	{
		return *this==x||*this<x;
	}
	
	inline bool operator>=(const High_Accuracy_Algorithm x)const
	{
		return *this==x||*this>x;
	}
	
	inline High_Accuracy_Algorithm operator=(const int x)
	{
		High_Accuracy_Algorithm tmp;
		int a=x; 
		for(tmp.n=0;a>0;++tmp.n)
		{
			tmp.num[tmp.n]=a%maxnum;
			a/=maxnum;
		}
		return tmp;
	}
};

inline High_Accuracy_Algorithm power(const int base,const int index)
{
	High_Accuracy_Algorithm tmp,ans;
	int now=index;
	{
	  	tmp=NUM[1];
	   	string a;
	   	int m=base;
	   	for(int i=0;m>0;++i,m/=10)
	   	{
	   		a.push_back(m%10+'0');
		}
		int len=a.length();
		for(int i=0;i<len>>1;++i)
		{
			swap(a[i],a[len-i-1]);
		}
		ans=a;
	}
	do
	{	
		if(now%2==1)
		{
			tmp*=ans;
		}
		now/=2;
		ans*=ans;
	}
	while(now>0);
	return tmp;
}

inline ostream& operator<<(ostream & os,const High_Accuracy_Algorithm &c)
{
	if(c.P_or_N)
	{
		os<<'-';
	}
	os<<c.num[c.n-1];
	for(int i=c.n-2;i>=0;--i)
	{
		if(c.num[i]==0)
		{
			os<<"00000000";
			continue;
		}
		for(int j=maxnum/10;j>c.num[i];j/=10)
		{
			os<<'0';
		}
		os<<c.num[i];
	}
	return os;
}

inline istream& operator>>(istream & is,High_Accuracy_Algorithm &c)
{
	string tmp;
	is>>tmp;
	c=tmp;
	return is;
}
#define INF 0x3fffffffffffffff
using namespace std;
HAA a;
int b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>b>>a;
	cout<<radical_sign(a,b)<<endl;
	return 0;
}

