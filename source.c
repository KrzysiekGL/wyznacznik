#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generujMacierzKwa(int wymiar, macierz[wymiar][wymiar]);
void drukujMacierzKwa(int wymiar, macierz[wymiar][wymiar]);
double wyznacznikMacierzy(int wymiar, int macierz[wymiar][wymiar]);
double wyznacznik2na2(int macierz[2][2]);
void przepiszMacierz(int wymiar, int zMacierz[wymiar][wymiar], int doMacierz[wymiar][wymiar]);
void wykerslMacierz(int wymiar, int kolumna, int wiersz, int zMacierz[wymiar][wymiar], int doMacierz[wymiar-1][wymiar-1]);

int main()
{
    //test funkcji wykreslMacierz
    int A[4][4];
    int B[3][3];

    generujMacierzKwa(4, A);
    drukujMacierzKwa(4, A);
    wykerslMacierz(4, 2, 0, A, B);
    drukujMacierzKwa(3, B);

    return 0;
}

double wyznacznikMacierzy(int wymiar, int macierz[wymiar][wymiar])
{
    double wyznacznik;
    if (wymiar == 2) return wyznacznik2na2(macierz);
    

}

double wyznacznik2na2(int macierz[2][2])
{
    return (macierz[0][0]*macierz[1][1]-macierz[0][1]*macierz[1][0]);
}

void przepiszMacierz(int wymiar, int zMacierz[wymiar][wymiar], int doMacierz[wymiar][wymiar])
{
    for(int x = 0 ; x < wymiar ; x++)
        for(int y = 0 ; y < wymiar ; y++)
            doMacierz[x][y] = zMacierz[x][y];
}

void wykerslMacierz(int wymiar, int kolumna, int wiersz, int zMacierz[wymiar][wymiar], int doMacierz[wymiar-1][wymiar-1])
{
    int doX = 0;
    for(int x = 0 ; x < wymiar ; x++)
    {
        int doY = 0;
        for(int y = y ; y < wymiar ; y++)
        {
            if(x != kolumna && y != wiersz)
            {
                doMacierz[doX][doY] = zMacierz[x][y]
                doY++;
            }
        }
        doX++;
    }
}

void generujMacierzKwa(int wymiar, macierz[wymiar][wymiar])
{
    srand(time(NULL));
    for(int x = 0 ; x < wymiar ; x++)
        for(int y = 0 ; y < wymiar ; y++)
            macierz[x][y] = rand()% 10 +1;
}

void drukujMacierzKwa(int wymiar, macierz[wymiar][wymiar])
{
    printf("\n");
    for(int x = 0 ; x < wymiar ; x++)
    {
        printf("\n");
        for(int y = 0 ; y < wymiar ; y++)
            printf("%d\t", macierz[x][y]);
    }
}