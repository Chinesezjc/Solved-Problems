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
int n,m,a,b,c;
map<int,map<int,int> > Map;
const int xx[]={0,1,0,-1},yy[]={1,0,-1,0};
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if((n&1)&&(m&1))
    {
        cout<<"First"<<endl;
        cout<<(n>>1)+1<<' '<<(m>>1)+1<<' '<<1<<endl;
        Map[(n>>1)+1][(m>>1)+1]=1;
    }
    else
    {
        cout<<"Second"<<endl;
    }
    while(cin>>a>>b>>c)
    {
        if(c==0)
        {
            c=-1;
        }
        for(int i=0;i<4;++i)
        {
            int x=a+xx[i],y=b+yy[i];
            if(c==Map[x][y])
            {
                cout<<"Buwanle"<<endl;
                return 0;
            }
        }
        Map[a][b]=c;
        cout<<n-a+1<<' '<<m-b+1<<' '<<((c==-1?1:0)^((n&1)&&(m&1)))<<endl;
        Map[n-a+1][m-b+1]=((c==-1?1:0)^((n&1)&&(m&1)))?1:-1;
    }
    return 0;
}