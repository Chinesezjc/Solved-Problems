//This Code was made by Chinese_zjc_.
#include<cstdio>
#include<cmath>
#define int long long
#define PI 3.14159265358979323
#define EQUAL 0.00000000000001
#define double long double
using namespace std;
int T,k;
double r,R,v,t,siz[5],atime;
bool answered;
double _360topi(const double IN)
{
    return IN/180*PI;
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%Lf%Lf%Lf%Lf%lld",&r,&R,&v,&t,&k);
        answered=false;
        if(!(k&1))
        {
            puts("no");
            continue;
        }
        siz[1]=_360topi(180)-atan((cos(_360topi(18))*r)/(R-sin(_360topi(18))*r));
        siz[2]=_360topi(180)-atan((cos(_360topi(54))*r)/(R+sin(_360topi(54))*r));
        atime=PI*2/k;
        for(int i=1;i<=2;++i)
        {
            int tim=siz[i]/atime+EQUAL;
            if(abs(tim*atime-siz[i])<EQUAL)
            {
                puts("no");
                answered=true;
                break;
            }
        }
        if(!answered)
        {
            puts("yes");
        }
    }
    return 0;
}