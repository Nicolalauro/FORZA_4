/*
    DATA:22/02/22
    Classe 2C inf
    Lauro Nicola
    traccia:FORZA 4

*/
// librerie
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
// costanti
#define MAX 7
#define MIN 6
#define GRAVITY 1
#define WIN_1 2
#define WIN_2 3
#define P 42
// dichiarazione matrici e variabili necessari
char forza[MIN][MAX];
char nome1[CHAR_MAX];
char nome2[CHAR_MAX][CHAR_MAX];
int colonna, check1;
int j, puntiX = 0;
int puntiO = 0, pareggio = 0;
int a = 0, b = 0;

// funzioni

// calcola punteggio
void punteggio()
{
    printf("\npunteggio %s: %d\n", nome1, puntiX);
    printf("\npunteggio %s: %d\n", nome2, puntiO);
}

// controlla se X ha vinto
void check_X()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (forza[i][j] == 'X' && forza[i][j + 1] == 'X' && forza[i][j + 2] == 'X' && forza[i][j + 3] == 'X')
            {
                check1 = WIN_1;
                
            }

            if (forza[j][i] == 'X' && forza[j + 1][i] == 'X' && forza[j + 2][i] == 'X' && forza[j + 3][i] == 'X')
            {
                check1 = WIN_1;
                
            }
        }

        for (int i = 0; i <= 3; i++)
        {

            for (int j = 5; j >= 3; j--)
            {

                if (forza[j][i] == 'X' && forza[j - 1][i + 1] == 'X' && forza[j - 2][i + 2] == 'X' && forza[j - 3][i + 3] == 'X')
                {
                    check1 = WIN_1;
                }
            }
        }
    }

    for (int i = 6; i >= 3; i--)
    {
        for (int j = 5; j >= 3; j--)
        {
            if (forza[j][i] == 'X' && forza[j - 1][i - 1] == 'X' && forza[j - 2][i - 2] == 'X' && forza[j - 3][i - 3] == 'X')
            {
                check1 = WIN_1;
            }
        }
    }
}

// controlla se O Ha vinto
void check_O()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (forza[i][j] == 'O' && forza[i][j + 1] == 'O' && forza[i][j + 2] == 'O' && forza[i][j + 3] == 'O')
            {
                check1 = WIN_2;
            }
            if (forza[j][i] == 'O' && forza[j + 1][i] == 'O' && forza[j + 2][i] == 'O' && forza[j + 3][i] == 'O')
            {
                check1 = WIN_2;
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 5; j >= 3; j--)
        {

            if (forza[j][i] == 'O' && forza[j - 1][i + 1] == 'O' && forza[j - 2][i + 2] == 'O' && forza[j - 3][i + 3] == 'O')
            {
                check1 = WIN_2;
            }
        }
    }

    for (int i = 6; i >= 3; i--)
    {
        for (int j = 5; j >= 3; j--)
        {
            if (forza[j][i] == 'O' && forza[j - 1][i - 1] == 'O' && forza[j - 2][i - 2] == 'O' && forza[j - 3][i - 3] == 'O')
            {
                check1 = WIN_2;
            }
        }
    }
}

// azzera il tavolo di gioco
void azzera()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= MIN; j++)
        {
            forza[i][j] = ' ';
        }
    }
}

//  creare la matrice
void matrice()
{
    printf("\t\t\t\t   0   1   2   3   4   5   6 \n");
    for (int i = 0; i < MIN; i++)
    {
        printf("\t\t\t\t ");
        for (int j = 0; j < MAX; j++)
        {
            printf("| %c ", forza[i][j]);
        }
        printf("|\n");
    }
}

// istruzioni
void istruzioni()
{
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                      REGOLE                                 *\n");
    printf("*                      FORZA 4                                *\n");
    printf("*                                                             *\n");
    printf("* Vince la partita chi allinea per primo in orizzontale       *\n");
    printf("* o verticale o obliquo quattro pedine                        *\n");
    printf("* Lo scopo del gioco e' riuscire ad allineare quattro pedine  *\n");
    printf("* dello stesso segno nella scacchiera di gioco sia            *\n");
    printf("* in verticale, orizzontale o obliquo                         *\n");
    printf("*                                                             *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
}

// assegna nomi utente
void nomi()
{
    puntiO = 0;
    puntiX = 0;
    printf("PLAYER 1 INSERISCI IL TUO NOME: ");
    scanf("%s", &nome1);
    printf("PLAYER 2 INSERISCI IL TUO NOME: ");
    scanf("%s", &nome2);
}

// Forza di gravita
void check_gravity(int colonna)
{
    for (int i = 5; i >= 0; i--)
    {

        if (forza[i][colonna] == ' ')
        {
            j = i;
            check1 = 1;
            break;
        }
    }
}

// player 1
void n_1()
{
    printf("%s \x82 IL TUO TURNO \n", nome1);
    printf("INSERISCI LA COLONNA: ");
    scanf("%d", &colonna);
    check_gravity(colonna);
    if (colonna < 0 || colonna > 6)
    {
        printf("COLONNA NON VALIDA");
        n_1();
    }
    else if (forza[0][colonna] == 'X' || forza[0][colonna] == 'O')
    {
        printf("CASELLA GIA OCCUPATA");
        n_1();
    }
    if (check1 == 1)
    {
        forza[j][colonna] = 'X';
        pareggio++;
        matrice();
    }

    check_X();
}

// player 2
void n_2()
{
    printf("%s \x82 IL TUO TURNO \n", nome2);
    printf("INSERISCI LA COLONNA: ");
    scanf("%d", &colonna);
    check_gravity(colonna);
    if (colonna < 0 || colonna > 6)
    {
        printf("CASELLA GIA OCCUPATA");
        n_2();
    }
    else if (forza[0][colonna] == 'X' || forza[0][colonna] == 'O')
    {
        printf("CASELLA GIA OCCUPATA");
        n_2();
    }
    if (check1 == 1)
    {
        forza[j][colonna] = 'O';
        pareggio++;
        matrice();
    }

    check_O();
}

// inizio del gioco
void gioco()
{
    azzera();
    matrice();
    while (check1 != WIN_1 || check1 != WIN_2 || pareggio != P)
    {
        n_1();
        if (check1 == WIN_1 || check1 == WIN_2 || pareggio == P)
        {

            break;
        }
        n_2();
        if (check1 == WIN_1 || check1 == WIN_2 || pareggio == P)
        {
            break;
        }
    }

    if (check1 == WIN_1)
    {
        printf("\n%s HAI VINTO!!!!\n", nome1);

        puntiX++;
    }
    else if (check1 == WIN_2)
    {
        printf("\n %s HAI VINTO!!!!\n", nome2);
        puntiO++;
    }
    else
        printf("\nNESSUNO HA VINTO");
    punteggio();
}

// avvia rivincita
void rivincita()
{
    gioco();
}

// menu
void menu()
{

    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n");
    printf("*                       MENU                         *\n");
    printf("*                      FORZA 4                       *\n");
    printf("* [1] NUOVA PARTITA                                  *\n");
    printf("* [2] RIVINCITA                                      *\n");
    printf("* [3] PUNTEGGIO                                      *\n");
    printf("* [4] REGOLE                                         *\n");
    printf("* [0] EXIT                                           *\n");
    printf("*                                                    *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n\n");
}

void forza4()
{

    int scelta = getchar();

    // MENU (che si ripete finche l'utente non inserisce 0)

    do
    {
        menu();
        printf("scegli cosa fare: ");
        //controlla se scelta e un carattere o un numero
        if (scanf("%d", &scelta))
        {
            {
                switch (scelta)
                {

                //  [1] NUOVA PARTITA
                case 1:
                    printf("\t\t\t\t\t\t FORZA 4\n");
                    nomi();
                    gioco();
                    system("pause");
                    break;
                //  [2] RIVINCITA
                case 2:
                    rivincita();
                    system("pause");
                    break;
                //  [3] PUNTEGGIO
                case 3:
                    punteggio();
                    system("pause");
                    break;
                //  [4] ISTRUZIONI
                case 4:
                    istruzioni();
                    system("pause");
                    break;
                //  [0] EXIT
                case 0:
                    exit(0);
                    break;
                // default
                default:
                    printf("INSERISCI UN NUMERO GIUSTO\n");
                    break;
                }
            }
        }
        //fa ripetere se scelta e un carattere
        else
        printf("INSERISCI UN NUMERO\n");
        forza4();
    } while (scelta != 0);
}

// int main
int main()
{
    printf("PREMI INVIO PER INIZIARE");
    forza4();
    system("pause");
    return 0;
}