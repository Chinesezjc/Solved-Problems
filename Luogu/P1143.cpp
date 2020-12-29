//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int l[129],a,b,num;
char r[16];
bool is(char c)
{
	for(int i=0;i<=15;++i)
	{
		if(c==r[i])
		{
			return true;
		}
	}
	return false;
}
void read()
{
	num=0;
	char c=getchar();
	while(!is(c))
	{
		c=getchar();
	}
	while(is(c))
	{
		num=num*a+l[c];
		c=getchar();
	}
}
void write(int now)
{
	if(now==0)
	{
		return;
	}
	write(now/b);
	cout<<r[now%b];
}
signed main()
{
	l['0']=0;
	l['1']=1;
	l['2']=2;
	l['3']=3;
	l['4']=4;
	l['5']=5;
	l['6']=6;
	l['7']=7;
	l['8']=8;
	l['9']=9;
	l['A']=10;
	l['B']=11;
	l['C']=12;
	l['D']=13;
	l['E']=14;
	l['F']=15;
	r[0]='0';
	r[1]='1';
	r[2]='2';
	r[3]='3';
	r[4]='4';
	r[5]='5';
	r[6]='6';
	r[7]='7';
	r[8]='8';
	r[9]='9';
	r[10]='A';
	r[11]='B';
	r[12]='C';
	r[13]='D';
	r[14]='E';
	r[15]='F';
	cin>>a;
	read();
	cin>>b;
	write(num);
	if(num==0)
	{
		cout<<0;
	}
	return 0;
}

