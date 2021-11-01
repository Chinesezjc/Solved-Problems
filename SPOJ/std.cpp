#include <cstdio>

using namespace std;

const int mo=1000000007;
int f[25][25][21000];
int opt[25][25][2][2];
int a[25];
int jc[21000],Pow[21000];
int n,m,x,y,z,Test;

int Power(int x,int y)
{
	int res=1;
	for (;y;y/=2)
	{
		if (y & 1) res=(long long)res*x % mo;
		x=(long long)x*x % mo;
	}
	return(res);
}

void Prepare()
{
	jc[0]=1;Pow[0]=1;
	for (int i=1;i<=20000;++i)
	{
		jc[i]=(long long)jc[i-1]*i % mo;
		Pow[i]=Power(jc[i],mo-2);
	}
}

int C(int x,int y)
{
	int res=jc[x];
	res=(long long)res*Pow[y] % mo;
	res=(long long)res*Pow[x-y] % mo;
	return(res);
}

int main()
{
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	Prepare();
	scanf("%d",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i)
			scanf("%d",&a[i]);
		for (int i=m-1;i>=1;--i)
			for (int j=i+1;j<=m;++j)
				for (int k=a[i+1]-1;k>=a[i];--k)
				{
					f[i][j][k]=0;
					x=j-i;
					if (x==1) f[i][j][k]=1;
					if (x==2) f[i][j][k]=C(a[j]-k-2,a[i+1]-k-1);
					if (x<=2) continue;
					if (x & 1)
					{
						for (int mid=i+2;mid<j;mid+=2)
						{
							f[i][j][k]+=(long long)f[i][mid][k]*f[mid][j][a[mid]] % mo *C(a[j]-k-2,a[mid]-k-1) % mo;
							if (f[i][j][k]>=mo) f[i][j][k]-=mo;
						}
						if (a[i+1]-k>1) f[i][j][k]+=f[i][j][k+1];
						if (f[i][j][k]>=mo) f[i][j][k]-=mo;
					}
					else
					{
						for (int mid=i+1;mid<j;mid+=2)
						{
							f[i][j][k]+=(long long)f[i][mid][k]*f[mid][j][a[mid]] % mo * C(a[j]-k-2,a[mid]-k-1) % mo;
							if (f[i][j][k]>=mo) f[i][j][k]-=mo;
						}
					}
				}
		for (int i=1;i<=m;++i)
			for (int j=1;j<=m;++j)
				for (int k1=0;k1<=1;++k1)
					for (int k2=0;k2<=1;++k2)
						opt[i][j][k1][k2]=0;
		for (int i=1;i<=m;++i)
			for (int k1=0;k1<=1;++k1)
				for (int k2=0;k2<=1;++k2)
					opt[i][i][k1][k2]=1;
		for (int i=m-1;i>=1;--i)
			for (int j=i+1;j<=m;++j)
				for (int k1=1;k1>=0;--k1)
					for (int k2=1;k2>=0;--k2)
					{
						x=j-i;
						if (x==1) opt[i][j][k1][k2]=1;
						if (x==2) opt[i][j][k1][k2]=C(a[j]-a[i]-k1-k2,a[i+1]-a[i]-k1);
						if (x<=2) continue;
						if (k1 & k2)
						{
							opt[i][j][k1][k2]=f[i][j][a[i]];
							continue;
						}
						if (x & 1)
						{
							if (!k1)
								for (int mid=i;mid<j;mid+=2)
								{
									opt[i][j][k1][k2]+=(long long)opt[i][mid][k1][1]*opt[mid][j][1][k2] % mo *C(a[j]-a[i]-k1-k2,a[mid]-a[i]-k1) % mo;
									if (opt[i][j][k1][k2]>=mo) opt[i][j][k1][k2]-=mo;
								}
							else
								for (int mid=j;mid>=i;mid-=2)
								{
									opt[i][j][k1][k2]+=(long long)opt[i][mid][k1][1]*opt[mid][j][1][k2] % mo *C(a[j]-a[i]-k1-k2,a[mid]-a[i]-k1) % mo;
									if (opt[i][j][k1][k2]>=mo) opt[i][j][k1][k2]-=mo;
								}
						}
						else
							for (int mid=i+1;mid<=j;mid+=2)
							{
								opt[i][j][k1][k2]+=(long long)opt[i][mid][k1][1]*opt[mid][j][1][k2] % mo *C(a[j]-a[i]-k1-k2,a[mid]-a[i]-k1) % mo;
								if (opt[i][j][k1][k2]>=mo) opt[i][j][k1][k2]-=mo;
							}
					}
		printf("%d\n",opt[1][m][0][0]);
	}
	return 0;
}
