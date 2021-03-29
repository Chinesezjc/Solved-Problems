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
int a,b,c;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>c;
    for(int i=1;i<=2000000;++i)
    {
        a-=i;
        b-=i;
        if(a<0)
        {
            c+=a;
            a=0;
        }
        if(b<0)
        {
            c+=b;
            b=0;
        }
        if(a<0||b<0||c<0)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    return 0;
}