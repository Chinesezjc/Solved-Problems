//This Code was made by Chinese_zjc_.
#include "combo.h"
#include <fstream>

std::string guess_sequence(int N)
{
    std::string ans = "";
    ans += press("AB") ? (press("A") ? 'A' : 'B') : (press("X") ? 'X' : 'Y');
    std::string c = "ABXY";
    c.erase(c.find(ans), 1);
    if (N == 1)
        return ans;
    for (int i = 2; i < N; ++i)
        switch (press(ans + c[1] + ans + c[2] + c[0] + ans + c[2] + c[1] + ans + c[2] + c[2]) - ans.length())
        {
        case 0:
            ans += c[0];
            break;
        case 1:
            ans += c[1];
            break;
        case 2:
            ans += c[2];
            break;
        }
    ans += press(ans + c[0]) == N ? c[0] : (press(ans + c[1]) == N ? c[1] : c[2]);
    return ans;
}
