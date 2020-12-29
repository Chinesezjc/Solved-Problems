//This code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
#define pi 3.14159265358979323
using namespace std;
int lsz,lfz,s,f;
double jsz,jfz,xsz,ysz,xfz,yfz;
double sqr(double now)
{
	return now*now;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>lsz>>lfz>>s>>f;
	jsz=s*30+f*0.5;
	jfz=f*6;
	if(jsz==0)
	{
		xsz=0;
		ysz=lsz;
	}
	if(0<jsz&&jsz<90)
	{
		xsz=cos((90-jsz)/180*pi)*lsz;
		ysz=sin((90-jsz)/180*pi)*lsz;
	}
	if(jsz==90)
	{
		xsz=lsz;
		ysz=0;
	}
	if(90<jsz&&jsz<180)
	{
		xsz=cos((jsz-90)/180*pi)*lsz;
		ysz=sin((jsz-90)/180*pi)*lsz*(-1);
	}
	if(jsz==180)
	{
		xsz=0;
		ysz=-lsz;
	}
	if(180<jsz&&jsz<270)
	{
		xsz=cos((270-jsz)/180*pi)*lsz*(-1);
		ysz=sin((270-jsz)/180*pi)*lsz*(-1);
	}
	if(jsz==270)
	{
		xsz=-lsz;
		ysz=0;
	}
	if(270<jsz&&jsz<360)
	{
		xsz=cos((jsz-270)/180*pi)*lsz*(-1);
		ysz=sin((jsz-270)/180*pi)*lsz;
	}
	if(jfz==0)
	{
		xfz=0;
		yfz=lfz;
	}
	if(0<jfz&&jfz<90)
	{
		xfz=cos((90-jfz)/180*pi)*lfz;
		yfz=sin((90-jfz)/180*pi)*lfz;
	}
	if(jfz==90)
	{
		xfz=lfz;
		yfz=0;
	}
	if(90<jfz&&jfz<180)
	{
		xfz=cos((jfz-90)/180*pi)*lfz;
		yfz=sin((jfz-90)/180*pi)*lfz*(-1);
	}
	if(jfz==180)
	{
		xfz=0;
		yfz=-lfz;
	}
	if(180<jfz&&jfz<270)
	{
		xfz=cos((270-jfz)/180*pi)*lfz*(-1);
		yfz=sin((270-jfz)/180*pi)*lfz*(-1);
	}
	if(jfz==270)
	{
		xfz=-lfz;
		yfz=0;
	}
	if(270<jfz&&jfz<360)
	{
		xfz=cos((jfz-270)/180*pi)*lfz*(-1);
		yfz=sin((jfz-270)/180*pi)*lfz;
	}
	cout<<fixed<<setprecision(20)<<sqrt(sqr(xsz-xfz)+sqr(ysz-yfz))<<endl;
	return 0;
}

