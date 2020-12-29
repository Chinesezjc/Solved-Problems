#include <cstdio>
using namespace std;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    n -= k;
    if (k == 1)
    {
        puts("0");
        return 0;
    }
    printf("%d", n);
    return 0;
}
