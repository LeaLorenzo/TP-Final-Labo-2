#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int x){                                                              /// Cambia la combinacion de color de fondo y frente
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y){                                                       /// Cambia las coordenadas del cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver){                                                       /// funcion para mostrar o esconder el cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = ver;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void cuadro(int x1, int y1, int x2, int y2)
{
    int i;
    for(i=x1; i<x2; i++)
    {
        gotoxy(i, y1);printf("Ä"); // linea horizontal superior
        gotoxy(i, y2);printf("Ä"); // linea horizontal inferior
    }

    for(i=y1; i<y2; i++)
    {
        gotoxy(x1, i);printf("³"); // linea horizontal superior
        gotoxy(x2, i);printf("³"); // linea horizontal inferior
    }

    gotoxy(x1, y1); printf("Ú"); // Esquinas del cuadro
    gotoxy(x1, y2); printf("À"); // Esquinas del cuadro
    gotoxy(x2, y1); printf("¿"); // Esquinas del cuadro
    gotoxy(x2, y2); printf("Ù"); // Esquinas del cuadro
}
