#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} 
int main()
{
   int x, y;
 
   x = 0;
   y = 10;
 
   gotoxy(x, y);
 
   printf("C program to change cursor position.");
 
   getch();
   return 0;
}