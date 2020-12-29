#include<string>
#include<iostream>
using namespace std;
string num;
int what,it=-1;
int main()
{
	cin>>num;
	for(int i=0;i<num.length();++i)
	{
		if(num[i]=='.')
		{
			what=1;
			it=i;
			break;
		}
		if(num[i]=='/')
		{
			what=2;
			it=i;
			break;
		}
		if(num[i]=='%')
		{
			what=3;
			it=i;
			break;
		}
	}
	for(int i=0;i<it/2;++i)
	{
		swap(num[i],num[it-1-i]);
	}
	for(int i=it+1;i<=it+(num.length()-it)/2;++i)
	{
		swap(num[i],num[num.length()+it-i]);
	}
	while(num[0]=='0')
	{
		num.erase(0,1);
		--it;
	}
	if(!('0'<=num[0]&&num[0]<='9'))
	{
		num.insert(0,1,'0');
		++it;
	}
	if(it<-1)
	{
		it=-1;
	}
	while(num[it+1]=='0')
	{
		num.erase(it+1,1);
	}
	while(what==1&&num[num.length()-1]=='0')
	{
		num.erase(num.length()-1,1);
	}
	if(!('0'<=num[it+1]&&num[it+1]<='9'))
	{
		num.insert(it+1,1,'0');
	}
	if(what==3)
	{
		num.erase(it+1,1);
	}
	cout<<num;
	return 0;
}
