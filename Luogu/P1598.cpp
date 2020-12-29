#include<cstdio>
using namespace std;
int tj[26],max;
char tmp;
void get()
{
	do
	{
		tmp=getchar();
	}
	while(!('A'<=tmp&&tmp<='Z')&&tmp!=EOF);
}
int main()
{
	get();
	while(tmp!=EOF)
	{
		++tj[tmp-'A'];
		get();
	}
	for(char i='A';i<='Z';++i)
	{
		if(tj[i-'A']>max)
		{
			max=tj[i-'A'];
		}
	}
	while(max>0)
	{
		--max;
		for(char i='A';i<='Z';++i)
		{
			if(tj[i-'A']>max)
			{
				putchar('*');
			}
			else
			{
				putchar(' ');
			}
			putchar(' ');
		}
		puts("");
	}
	for(char i='A';i<='Z';++i)
	{
		putchar(i);
		putchar(' ');
	}
	return 0;
}
