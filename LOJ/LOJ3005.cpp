//This Code was made by Chinese_zjc_.
#include "memory.h"
//xxxxxxxxxxxxxxxxxxxxxx
//[    ][    ][     ][ ]
//now   doing pos    last
//0:<>
//1:[]
// #define debug
#ifdef debug
#include <fstream>
std::ofstream ouf("out.out");
#endif
int Memory(int N, int M)
{
    int now_depth = M & 63, doing_depth = M >> 6 & 63, pos = M >> 12 & 127, last = M >> 19;
    if (now_depth > N / 2)
        return -2;
    if (doing_depth > N / 2)
        return -1;
    ++pos;
    if (pos < 1 || pos > N)
        return Get(1);
    char g = Get(pos);
#ifdef debug
    ouf << g << std::endl;
#endif
    switch (g)
    {
    case '<':
        if (doing_depth == now_depth)
            last = 0;
        ++now_depth;
        break;
    case '[':
        if (doing_depth == now_depth)
            last = 1;
        ++now_depth;
        break;
    case '>':
        --now_depth;
        if (now_depth < 0 || (doing_depth == now_depth && last != 0))
            return -2;
        break;
    case ']':
        --now_depth;
#ifdef debug
        ouf << pos << ' ' << now_depth << std::endl;
#endif
        if (now_depth < 0 || (doing_depth == now_depth && last != 1))
            return -2;
        break;
    }
#ifdef debug
    ouf << now_depth << ' ' << doing_depth << ' ' << pos << ' ' << last << std::endl;
#endif
    if (pos == N)
    {
        if (now_depth)
            return -2;
        pos = 0;
        ++doing_depth;
    }
    return now_depth | doing_depth << 6 | pos << 12 | last << 19;
}