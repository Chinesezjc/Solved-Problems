//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
bool isr[50001];
int len,n,year,month,day,hour,minute,second,days;
signed main()
{
//	std::ios::sync_with_stdio(false);
	for(int i=0;i<=20000;i+=4)
	{
		isr[i]=true;
	}
	for(int i=0;i<=20000;i+=100)
	{
		isr[i]=false;
	}
	for(int i=0;i<=20000;i+=400)
	{
		isr[i]=true;
	}
	cin>>n;
	while(n)
	{
		--n;
		cin>>len>>year>>month>>day>>hour>>minute>>second;
		len=(1ll<<len>>1)-1;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			days=31;
		}
		if(month==4||month==6||month==9||month==11)
		{
			days=30;
		}
		if(month==2)
		{
			if(isr[year])
			{
				days=29;
			}
			else
			{
				days=28;
			}
		}
		while(len>=86400)
		{
			len-=86400;
			++day;
			if(day>days)
			{
				day=1;
				++month;
				if(month>12)
				{
					month=1;
					++year;
				}
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				{
					days=31;
				}
				if(month==4||month==6||month==9||month==11)
				{
					days=30;
				}
				if(month==2)
				{
					if(isr[year])
					{
						days=29;
					}
					else
					{
						days=28;
					}
				}
			}
		}
		while(len)
		{
			--len;
			++second;
			if(second==60)
			{
				second=0;
				++minute;
				if(minute==60)
				{
					minute=0;
					++hour;
					if(hour==24)
					{
						hour=0;
						++day;
						if(day>days)
						{
							day=1;
							++month;
							if(month>12)
							{
								month=1;
								++year;
							}
							if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
							{
								days=31;
							}
							if(month==4||month==6||month==9||month==11)
							{
								days=30;
							}
							if(month==2)
							{
								if(isr[year])
								{
									days=29;
								}
								else
								{
									days=28;
								}
							}
						}
					}
				}
			}
		}
		cout<<year<<' '<<month<<' '<<day<<' '<<hour<<' '<<minute<<' '<<second<<endl;
	}
	return 0;
}

