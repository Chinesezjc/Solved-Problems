#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void HideCursor() //隐藏控制台的光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int y, int x)
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
int room = -1, n;
int a[100005][2], id = -1, pos;
void outputcolor(int id)
{
    if (id == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "red";
    }
    if (id == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << "green";
    }
    if (id == 2)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        cout << "blue";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
void reinput()
{
    ifstream fin("\\\\CE025\\share\\114514.txt");
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i][0] >> a[i][1];
}
void reoutput()
{
    ofstream fout("\\\\CE025\\share\\114514.txt");
    fout << n << endl;
    for (int i = 1; i <= n; i++)
        fout << a[i][0] << ' ' << a[i][1] << endl;
}
void endthis()
{
    if (room < 0)
        return;
    a[pos][1] ^= 1 << id;
    reoutput();
}

signed main()
{
    atexit(endthis);
    system("cls");

loop:
    do
    {
        cout << "welcome to Tanks!" << endl
             << endl;
        cout << "Please input the room number: ";
        cin >> room;
        if (room < 0)
            cout << endl
                 << endl
                 << "Invalid input";
        Sleep(1234);
        system("cls");
    } while (room < 0);

    reinput();
    pos = 0;
    for (int i = 1; i <= n; i++)
        if (a[i][0] == room)
            pos = i;
    if (!pos)
        a[pos = ++n][0] = room;
    if (a[pos][1] > 7)
    {
        if (room < 0)
            cout << "Room is full.";
        Sleep(1234);
        system("cls");
        goto loop;
    }
    if (!(a[pos][1] & 4))
        id = 2;
    if (!(a[pos][1] & 2))
        id = 1;
    if (!(a[pos][1] & 1))
        id = 0;
    a[pos][1] |= 1 << id;
    reoutput();

    HideCursor();
    cout << "You are ";
    outputcolor(id);
    cout << endl
         << endl;
    cout << "Waiting " << __builtin_popcount(a[pos][1]) << "/3" << endl;
    while (__builtin_popcount(a[pos][1]) < 3)
    {
        reinput();
        Sleep(10);
        gotoxy(2, 8);
        for (int i = 1; i <= n; i++)
            if (a[i][0] == room)
                pos = i;
        cout << __builtin_popcount(a[pos][1]);
    }
    system((".\\bin\\Debug\\Tanks.exe " + to_string(room) + " " + to_string(id)).c_str());

    return 0;
}