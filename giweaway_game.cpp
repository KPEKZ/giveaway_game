#include "PCH.h"

int main() {

    /*int a =0 , b = 0;
    Field field;
    field.SetSizeField(8);
    field.CreateField();
     field.DrawField();
     std::string s;

     std::cout << std::endl;*/
     
     //field.DeleteCell(a, b);

    /* for (int i = 0; i < 5; i++) {
         std::cout << " enter x, y : ";
         std::cin >> a >> b;
         field.SetCell(a, b,Cells::BLACK);
         field.DrawField();

     }*/

    Manager manager;
    manager.Init();
    while (1) {
        manager.MakeMove();
    }
     //std::cout << "add : ";
     //std::cin >> s;
     //field.ChooseCell(s);

    /*_setmode(_fileno(stdout), _O_WTEXT);

    std::wstring s = L"♕";
    std::wcout << s;*/
    
   /* SetConsoleOutputCP(CP_UTF8);
    wchar_t s[] = L"èéøÞǽлљΣæča\x01c4";
    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, s, -1, NULL, 0, NULL, NULL);
    char* m = new char[bufferSize];
    WideCharToMultiByte(CP_UTF8, 0, s, -1, m, bufferSize, NULL, NULL);
    wprintf(L"%S", m);*/


   // DWORD dwCount;
   // char title[] = "Игра Поддавки";
   // CharToOem(title, title);
   // COORD point;
   ///* point.X = 0;
   // point.Y = 0;*/
   //// LPDWORD lpWord = nullptr;
   // HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   // HANDLE hStIn = GetStdHandle(STD_INPUT_HANDLE);
   // SetConsoleTitle(title);
   // SetConsoleOutputCP(1251);
   // SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
   // FillConsoleOutputAttribute(hStdOut, 0, 2000, point, &dwCount); 
  //  Field f1;

  /*  int iPic[17][20] = {
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                   {0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,1,0,3},
                   {0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,3},
                   {0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,3},
                   {0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,3},
                   {0,1,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,3},
                   {0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,0,3},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                   {0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,3},
                   {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,3},
                   {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,3},
                   {0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,3},
                   {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,3},
                   {0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,3},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3} };

    if (hStdOut != INVALID_HANDLE_VALUE)
    {
        point.X = 0;
        point.Y = 0;
        if (SetConsoleCursorPosition(hStdOut, point))
        {
            for (int i = 0; i < 17; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (iPic[i][j] == 0)
                    {
                        if (SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | FOREGROUND_RED))
                        {
                            cout << (char)219;
                        }
                    }
                    if (iPic[i][j] == 1)
                    {
                        if (SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY))
                        {
                            cout << (char)177;
                        }
                    }
                    if (iPic[i][j] == 3)
                    {
                        point.Y++;
                        if (!SetConsoleCursorPosition(hStdOut, point)) { cout << "Error SetConsoleCursorPosition" << endl; }
                    }
                }
            }

        }
        else { cout << "Error SetConsoleCursorPosition..." << endl; }
        if (!CloseHandle(hStdOut)) { cout << "Error CloseHandle..." << endl; }
    }
    else { cout << "Error GetStdHandle..." << endl; }*/
    
    // очистка экрана
   /* for (int y = 0; y < 16; y++) {  
        point.Y = y;
        FillConsoleOutputAttribute(hStdOut, y << 4, 80, point, &dwCount);
        SetConsoleCursorPosition(hStdOut, point);
    }*/

   /* for (int x = 0; x < 16;x++) {
        point.X = x;
        FillConsoleOutputAttribute(hStdOut, x << 4, 80, point, &dwCount);
        SetConsoleCursorPosition(hStdOut, point);
    }
    */
   
    


    /*DWORD l;
    COORD point;
    point.X = 0; point.Y = 0;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    const TCHAR szMsg[] = "What's your name?\n";
    TCHAR szName[16];
    TCHAR szResp[32];
    DWORD dwCount = 0;
    char shape = '\u025CF';
    
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
    WriteConsole(hStdout, &szMsg, sizeof(szMsg), &dwCount, NULL);
    ReadConsole(hStdin, &szName, sizeof(szName), &dwCount, NULL);

    if (dwCount >= 2 &&
        '\n' == szName[dwCount - 1] &&
        '\r' == szName[dwCount - 2]) {
        szName[dwCount - 2] = '\0';
    }
    else if (dwCount > 0) {
        szName[dwCount] = '\0';
    }
   
    wsprintf(szResp, "Hello, %s!\n", szName);
  
    WriteConsole(hStdout, &szResp, lstrlen(szResp), &dwCount, NULL);
    cout << shape << endl;*/
    
    //char title[] = "Консольная программа";
    //CharToOem(title, title);
    //SetConsoleTitle(title);
    //SetConsoleOutputCP(1251);
    //SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
    //FillConsoleOutputAttribute(hout, 0, 2000, point, &l); // очистка экрана
    //for (int y = 0; y < 16; y++) {
    //    point.Y = y;
    //    FillConsoleOutputAttribute(hout, y << 4, 80, point, &l);
    //    SetConsoleCursorPosition(hout, point);
    //}
    //const char wor_ds[] = "WORD";
    //LPDWORD col = 0;
    //WriteFile(hin, wor_ds, sizeof(wor_ds), col, NULL);
    //char c;
    //ReadFile(hin, &c, 1, &l, NULL);
    //
    

   /* HWND myConsole = GetConsoleWindow();
    
    HDC hdc = GetDC(myConsole);
    
    int pixel = 0;

    COLORREF COLOR = RGB(255, 0, 0);

    for (double i = 0; i < M_PI * 4; i+=0.05) {
        SetPixel(hdc, pixel, static_cast<int>(50 + 25 * cos(i)), COLOR);
        pixel += 3;
    }
    
    ReleaseDC(myConsole, hdc);
    cin.ignore();*/
    return 0;
}