#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 1000
typedef struct{
char *caracterCitit;
int  *indicestareDestinatie;
char *caracterScris;
char *Go;
int numarTranz;
}Stare,*St;
Stare alocare()
{
    Stare stareAlocata;
    stareAlocata.caracterCitit = malloc(Max*sizeof(char));
    stareAlocata.indicestareDestinatie = malloc(Max*sizeof(int));
    stareAlocata.caracterScris = malloc(Max*sizeof(char));
    stareAlocata.Go = malloc(Max*sizeof(char));
    stareAlocata.numarTranz = 0;
    return stareAlocata;
}

int main()
{
    Stare stareArray[Max];
    int i, q, numarDeOrdine;;
    int *StariFinale = calloc(Max ,sizeof(int)); // Un vector care are 1 pe pozitia starii finale
    int numarDeStari,numarStariFinale,stareInitiala,stareCurenta;
    char *buffer = malloc(Max*sizeof(char));
    char *banda = malloc(Max*sizeof(char));
    FILE *f,*g,*h;
    f = fopen("tm.in","r");
    if (f == NULL)
        perror ("Error opening file");
    char *pch,*pch2;

    if ( fgets (buffer , 100 , f) != NULL ) //PRIMUL RAND
    {
        pch = strtok(buffer," ");
        numarDeStari = atoi(pch);
        while(pch != NULL)
        {
               pch = strtok(NULL," ");
               if(pch != NULL)
               {

                pch++;
                numarDeOrdine = atoi(pch);
                stareArray[numarDeOrdine] = alocare();

                }
        }
    }

    if( fgets(buffer,100,f) != NULL) //AL DOILEA RAND
    {
            pch = strtok(buffer," ");
            numarStariFinale = atoi(pch);
            while(pch != NULL)
            {
                pch = strtok(NULL," ");
                if(pch != NULL)
                {

                pch ++;
                numarDeOrdine = atoi(pch);
                StariFinale[numarDeOrdine] = 1;

                }
            }
    }

        fgets(buffer,100,f); //AL TREILEA RAND
        buffer++;
        stareInitiala = atoi(buffer);


        fgets(buffer,100,f); // AL PATRULEA RAND
        int number;
        int numarTranzitii = atoi(buffer);         //printf("%d",numarTranzitii);
        for(i=1;i<=numarTranzitii;i++)
        {
            fgets(buffer,1000,f);
            pch = strtok(buffer," ");
            pch++;
            stareCurenta = atoi(pch);
            pch = strtok(NULL," ");
            int number = stareArray[stareCurenta].numarTranz;
            stareArray[stareCurenta].caracterCitit[number] = *pch;
            pch = strtok(NULL," ");
            pch++;
            stareArray[stareCurenta].indicestareDestinatie[number] = atoi(pch);

            pch = strtok(NULL," ");
            stareArray[stareCurenta].caracterScris[number] = *pch;

            pch = strtok(NULL," ");
            if(pch != NULL)
                stareArray[stareCurenta].Go[number] = *pch;
            (stareArray[stareCurenta].numarTranz) ++;
        }
    // ****** CITIRE BANDA ********
        g = fopen("tape.in","r");
        if (g == NULL)
            perror ("Error opening file");
        fgets(banda,100,g);

// *** FISIER PT OUTPUT
     h = fopen("tape.out","w");
     if (h == NULL)
        perror ("Error opening file");
     stareCurenta = stareInitiala;
     i = 0;
// SAR PESTE ####
    while (1)
    {
        if(banda[i] != '#')
            break;
        else
            i++;
    }
    char x;
    int j;
    int k = 0 ;
    int ok;
    while (1)
    {
        ok = 0;
        x = banda[i];
        for(j = 0;j < stareArray[stareCurenta].numarTranz; j++)
        {
            if(stareArray[stareCurenta].caracterCitit[j] == x)
            {
            ok = 1;
            break;
            }
        }
        if(ok == 0)
            break;
        number = stareArray[stareCurenta].numarTranz;
        banda[i] = stareArray[stareCurenta].caracterScris[j];
        if(stareArray[stareCurenta].Go[j] == 'L')
            i--;
        if(stareArray[stareCurenta].Go[j] == 'R')
            i++;
        stareCurenta = stareArray[stareCurenta].indicestareDestinatie[j];
        k++;
        if(StariFinale[stareCurenta] == 1)
            break;
    }
    if(ok == 0)
        printf("SE AGATA");
    else
        printf("%s",banda);

    return 0;
}
