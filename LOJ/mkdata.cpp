#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

template <typename T>
void read(T &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c) && c != '-')
        c = getchar();
    if (c == '-')
        f = 1, c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    if (f)
        x = -x;
}

int n = 50000, m = 100000 - 2;

int main()
{
    freopen("data.in", "w", stdout);
    printf("%d %d\n", n, m);
    for (int i = 2; i < n; i++)
        printf("%d %d %d %d\n", i, i + 1, 1, 1);
    for (int i = 1; i <= m - n + 2; i++)
        printf("%d %d %d %d\n", 1, 2, i, m - n + 3 - i);
    return 0;
}