//program oblicza wyzacznik macierzy kwadratowej
//generowanej pseudolosowo
//metoda zasobożerna
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void generujMacierzKwa(int wymiar, int macierz[wymiar][wymiar]);
void drukujMacierzKwa(int wymiar, int macierz[wymiar][wymiar]);
int wyznacznikMacierzy(int wymiar, int macierz[wymiar][wymiar]);
int wyznacznik2na2(int macierz[2][2]);
void wykerslMacierz(int wymiar, int kolumna, int wiersz, int zMacierz[wymiar][wymiar], int doMacierz[wymiar-1][wymiar-1]);

int main()
{
    const int kwadrat = 10;
    int liczby[kwadrat][kwadrat];
    generujMacierzKwa(kwadrat, liczby);
    drukujMacierzKwa(kwadrat, liczby);
    printf("\nwyznacznik macierzy liczby[%d][%d] = %d\n", kwadrat, kwadrat, wyznacznikMacierzy(kwadrat, liczby));

    return 0;
}

int wyznacznikMacierzy(int wymiar, int macierz[wymiar][wymiar])
{  
    const int wymiarMinus = wymiar-1;
    int macierzBufor[wymiarMinus][wymiarMinus];
    int wyznacznik = 0;

    if (wymiar == 2) return wyznacznik2na2(macierz);

    for(int i = 0 ; i < wymiar ; i++)
    {
        wykerslMacierz(wymiar, 0, i, macierz, macierzBufor);
        wyznacznik += pow((-1),(i+2)) * macierz[0][i] * wyznacznikMacierzy(wymiarMinus, macierzBufor);
    }
    return wyznacznik;
}
void wykerslMacierz(int wymiar, int kolumna, int wiersz, int zMacierz[wymiar][wymiar], int doMacierz[wymiar-1][wymiar-1])
{
    int doX = 0;
    for(int x = 0 ; x < wymiar ; x++)
    {
        int doY = 0;
        for(int y = 0 ; y < wymiar ; y++)
        {
            if(x != kolumna && y != wiersz)
            {
                doMacierz[doX][doY] = zMacierz[x][y];
                doY++;
            }
        }
        if(doY == (wymiar-1)) doX++;        
    }
}

int wyznacznik2na2(int macierz[2][2])
{
    int wyznacznik = (macierz[0][0]*macierz[1][1]-macierz[0][1]*macierz[1][0]);
    return wyznacznik;
}

void generujMacierzKwa(int wymiar, int macierz[wymiar][wymiar])
{
    srand(time(NULL));
    for(int x = 0 ; x < wymiar ; x++)
        for(int y = 0 ; y < wymiar ; y++)
            macierz[x][y] = rand()% 10 +1;
}

void drukujMacierzKwa(int wymiar, int macierz[wymiar][wymiar])
{
    for(int x = 0 ; x < wymiar ; x++)
    {
        printf("\n");
        for(int y = 0 ; y < wymiar ; y++)
            printf("%d\t", macierz[x][y]);
    }
    printf("\n");
}