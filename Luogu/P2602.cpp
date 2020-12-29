//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int a,b;
int power(int A,int B)
{
    int tmp=1;
    while(B)
    {
        if(B&1)
        {
            tmp*=A;
        }
        A*=A;
        B>>=1;
    }
    return tmp;
}
int work(int limit,int now)
{
    int tmp=0;
    for(int i=0;power(10,i)<=limit;++i)
    {
        int l=limit/power(10,i+1),m=limit/power(10,i)-l*10,r=limit%power(10,i);
        if(now)
        {
            if(m>now)
            {
                tmp+=(l+1)*power(10,i);
            }
            if(m==now)
            {
                tmp+=l*power(10,i)+r+1;
            }
            if(m<now)
            {
                tmp+=l*power(10,i);
            }
        }
        else
        {
            if(m)
            {
                tmp+=l*power(10,i);
            }
            else
            {
                tmp+=(l-1)*power(10,i)+r+1;
            }
        }
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    for(int i=0;i<=9;++i)
    {
        cout<<work(b,i)-work(a-1,i)<<' ';
    }
    cout<<endl;
    return 0;
}