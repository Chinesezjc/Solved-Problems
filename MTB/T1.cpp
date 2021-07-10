#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<string>
#include<iomanip>


using namespace std;
char data_c[1000] = { 0 };
long long  data_i[1000] = { 0 };
long long pridata_i[1000] = { 0 };

long long fastmod(long long a, long long m, long long n);   //快速模
void extgcd(long long  a,long long  b,long long & d,long long & x,long long & y);
long long  inverse(long long a,long long n);   //求逆元
void ssgive2(long long & a, long long & b);   //生成两个素数，利用Miller-Rabin
long long lcm(long long a, long long b);   //最小公倍数
long long gcd(long long x,long long y);    //最大公约数
long long gete(long long l);              //求E
long long quickPower(long long a,long long b,long long c);
long long quickMult(long long a,long long b,long long c);
bool millerRabinPrimeTest(long long n);    //素数检测算法
int CalcBit(long long int num);//计算num的位数

int main()
{
	string data,pridata;
	cout << "************RSA算法测试*************" << endl;
	cout << "本次的参数:" << endl;
	long long p,q;
	int wd = 0;
	ssgive2(p,q);
	cout<<"p="<<p<<" q="<<q<<endl;
	long long n = p*q;
	cout << "n=" << n <<endl;
	long long l = lcm(p-1,q-1);
	cout << "l=" << l << endl;
	long long e = gete(l);
	cout << "e=" << e << endl;
	cout << "公钥=(" << e << "," << n <<")" << endl;
	long long d = inverse(e,l);
	cout << "d=" << d << endl;
	cout << "私钥=(" << d << "," << n <<")" << endl;
	wd = CalcBit(n);
	cout << "**********************************" << endl << endl;
	cout << "请输入需要加密的明文" << endl;
	cin >> data;
	strcpy_s(data_c, data.c_str());   //0-data.length()-1
	long long int len = data.length();
	cout << endl << "加密后生成的密文:";
	for (int t = 0; t < len; t++)
	{
		data_i[t] = (int)data_c[t];      //通过ascii将文字字符转换为数字从而进行加密
		pridata_i[t] = fastmod(data_i[t], e, n);
		cout << /*setfill('0') << setw(wd) <<*/ hex << pridata_i[t] << " ";
	}
	cout << endl << endl << "解密后的明文:";
	for (int t = 0; t < len; t++)
	{
		data_i[t] = fastmod(pridata_i[t], d, n);
		data_c[t] = (char)data_i[t];
		cout << data_c[t];
	}
	cout << endl;
	return 0;
}
long long quickMult(long long a,long long b,long long c)
{
    long long  result=0;
    while(b>0)
	{
        if(b&1)
            result=(result+a)%c;
        a=(a+a)%c;
        b>>=1;
    }
    return result;
}
long long quickPower(long long a,long long b,long long c)
{
    long long  result=1;
    while(b>0)
	{
        if(b&1)
        {
        	result=quickMult(result,a,c);
		}
        a=quickMult(a,a,c);
        b>>=1;
    }
    return result;
}
bool millerRabinPrimeTest(long long n)
{
    long long  d,x,newX,a=1;
    long long int i;
    for (i = 0; i < 4; i++)
        a *= rand();
    a=a%(n-3)+2;//随机第选取一个a∈[2,n-2]
    //printf("随机选取的a=%lld\n",a);
    long long int s=0;//s为d中的因子2的幂次数。
    d=n-1;  //d取初值n-1
    while((d&1)==0) //将d中因子2全部提取出来。
	{
        s++;
        d>>=1;
    }
    x=quickPower(a,d,n);
    for(i = 0; i < s; i++) //进行s次二次探测
	{
        newX=quickPower(x,2,n);
        if(newX == 1 && x != 1 && x != n-1)
            return false; //用二次定理的逆否命题，此时n确定为合数。
        x=newX;
    }
    if(x!=1)
        return false;   //用费马小定理的逆否命题判断，此时x=a^(n-1) (mod n)，那么n确定为合数。

    return true; //用费马小定理的逆命题判断。能经受住考验至此的数，大概率为素数。
}
long long gete(long long l)
{
	for(long long i = 2; i < l; ++i)
	{
		if(gcd(i,l)==1)
		{
			return i;
		}
	}
}

void ssgive2(long long &a,long long & b)
{
	unsigned seed = time(0);
	srand(seed);
	a = rand()%1000000;    //随机生成某个大小的数
	b = rand()%1000000;
	if(a == 2 || a == 3){	}
	else
	{
		if(a % 2 == 0)
		{
			a = a+1;
		}
		for(;;a+=2)
		{
			if(millerRabinPrimeTest(a))
			{
				break;
			}
		}
	}


	if(b == 2 || b == 3){	}
	else
	{

		if(b % 2 == 0)
		{
			b = b+1;
		}
		for(;;b+=2)
		{

			if(millerRabinPrimeTest(b))
			{
				break;
			}
		}
	}


}

long long gcd(long long x,long long y)
{
   while(x != y)
   {
   		if(x > y)
	  	{
	  		x = x - y;
		}
        else
        {
        	y = y - x;
		}
   }
   return x;
}

long long lcm(long long a, long long b)
{
	return a/gcd(a,b)*b;
}


long long fastmod(long long a, long long m, long long n)
{
	long long int c  = 0;
	long long int k = 0;
	long long int result = 1;
	long long int num[10000] = {0};

	for(long long int i=0; m>0; i++)
    {
        num[i] = m % 2;
        m /= 2;
        k = i;
    }
	for (long long int i = k;i >=0; i--)
	{

		result = result*result % n;
		if(num[i] == 1)
		{

			result = result * a % n;
		}
	}
	return result;
}


void extgcd(long long  a,long long  b,long long & d,long long & x,long long & y){
    if(!b)
	{
		d=a;
		x=1;
		y=0;
	}
    else
	{
		extgcd(b,a%b,d,y,x);
	    y-=x*(a/b);
	}
}
long long  inverse(long long a,long long m)
{
    long long d,x,y;
    extgcd(a,m,d,x,y);
    return d==1?(x+m)%m:-1;
}

int CalcBit(long long int num)//计算num的位数
{
	int cnt = 0;
	while (num / 16 != 0)
	{
		num = num / 16;
		cnt++;
	}
	cnt = cnt + 1;//num的位数

	return cnt;
}