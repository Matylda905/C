//Zadavam velikost (2-26) a diky nic se tvori sachovnice (napr vel. 10= 10x10), pak se vytvori sachovnice kdy po strana jsou napsany cisla  avodorovne pismena, pak se zepta zda chce znovu...
//cerny " ";bily 219;A 65...

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vel;
    char sachovnice[26][26];
    int i, j;
    
    printf("Zadejte velikost sachovnice (2-26): ");
    scanf("%d", &vel);

    if(vel < 2 || vel > 26){
        printf("Neplatna velikost sachovnice.\n");
        return 1;
    }

    

    for (i=0; i<vel;i++){
        for (j=0; j<vel;j++){
            if((i+j)%2==0){
                sachovnice[i][j] = ' ';
            } else {
                sachovnice[i][j] = 219;
            }
        }
    }

    printf("  ");

    for (i=0; i<vel;i++){
        printf("%c ", 65+i);
    }

    printf("\n");

    for (i=0; i<vel;i++){
        if (i<9){
            printf("%d ", vel-i);
        } else {
            printf("%d", vel-i);
        }
        for (j=0; j<vel;j++){
            printf("%c ", sachovnice[i][j]);
        }
        printf("%d ", vel-i);
        printf("\n");
    }

    printf("  ");

    for (i=0; i<vel;i++){
        printf("%c ", 65+i);
    }

    





}