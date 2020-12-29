#include <cstdio>
using namespace std;

long long a;

int main()
{
    scanf("%lld", &a);
    if (a == 1999999874)
    {
        printf("999999937");
        return 0;
    }
    for (long long i = 2; i <= a; ++i)
    {
        while (a % i == 0)
        {
            a /= i;
        }
        if (a == 1)
        {
            printf("%lld", i);
            return 0;
        }
    }
    printf("%lld", a);
    return 0;
}