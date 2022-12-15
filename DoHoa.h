#include<windows.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
//void ShowCur(bool CursorVisibility);
void xoamanhinh();
void XoaManHinh();
void TextColor(int x);
void BackGroundColor(WORD color);
void resizeConsole(int width, int height);
void setColor(WORD color);
void gotoXY(SHORT posX, SHORT posY);
void vietChuoi(int x, int y, string a, int color); 
void viet(int x, int y, int z);
wchar_t* convertCharArrayToLPCWSTR(const char* charArray);
