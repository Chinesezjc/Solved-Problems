#include<string>
#include<iostream>
using namespace std;
string a,b;
int now,ans,first;
int main()
{
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.length();++i)
	{
		a[i]=tolower(a[i]);
	}
	for(int i=0;i<b.length();++i)
	{
		b[i]=tolower(b[i]);
	}
	a=' '+a+' ';
	b=' '+b+' ';
	if(b.find(a)==string::npos)
	{
		cout<<-1;
	}
	else
	{
		first=b.find(a);
		now=b.find(a);
		ans=0;
		while(b.find(a,now)!=string::npos)
		{
			now=b.find(a,now+1);
			++ans;
		}
		cout<<ans<<' '<<first;
	}
	return 0;
}
