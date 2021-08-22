#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,p;
struct zj{
    long long a[5][5];
    zj operator = (int k){
        a[1][1]=1;
        for (int i=1;i<=k;i++)
        a[1][1]*=10;
        a[1][1]%=p;
        a[1][2]=0;
        a[1][3]=0;
        a[2][1]=1;
        a[2][2]=1;
        a[2][3]=0;
        a[3][1]=1;
        a[3][2]=1;
        a[3][3]=1;
        return *this;
    }
    zj operator * (zj b){
        zj c;
           for (int i=1;i<=3;i++)
             for (int j=1;j<=3;j++){
                 c.a[i][j]=0;
                 for (int k=1;k<=3;k++){
                    c.a[i][j]+=(a[i][k])%p*(b.a[k][j])%p;
                    c.a[i][j]%=p;
                }
            }
        return c;
    }
    zj operator ^ (long long x){
        zj c,a;a=*this;
           for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                c.a[i][j]=(i==j);
        for(;x;x>>=1){
            if(x&1) c=c*a;
               a=a*a;
        }
        return c;
    }
}A[20],B;
long long pow10(int x){
    long long out=1;
    for (int i=1;i<=x;i++) out*=10;
    return out;
}
int main(){
    scanf("%lld%lld",&n,&p);
    int k=0;long long nn=n;
    while (nn) {k++;nn/=10;}
    for (int i=1;i<k;i++){
        A[i]=i;
        A[i]=A[i]^(pow10(i-1)*9);
    }
    nn=n-pow10(k-1)+1;
    A[k]=k;
    A[k]=A[k]^nn;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            B.a[i][j]=(i==j);
    for (int i=1;i<=k;i++) B=B*A[i];
    printf("%lld",B.a[3][1]);
    return 0;
}