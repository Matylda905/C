//hledam poklad souradnice (0-4),10 zivotu, zakladni pozice na 0:0, na pozicich 0:1,0:2,0:4 utesy, pokud na ne dopadneme odeberou se 2 zivoty + 1 zivot za pokus, pokud neuspeje pokus vypise se tzv Napoveda a pokud vyhrajem tak vypise konec atd, po kazdem pokus  se vypise ta tabulka/mapa s pozicemi a zivoty, atd. a hra pokracuje dokud nezvladneme najit poklad nebo neztratime vsechny zivoty, pohybuju se tak ze vypisu pozici X a Y

/*
mapa

    0 1 2 3 4
0   P ~ ~ ~ ~
1   X ~ ~ ~ ~	
2   X ~ ~ ~ ~
3   ~ ~ ~ ~ ~
4   X ~ ~ ~ ~
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int zivoty = 9;
    int poziceX = 0;
    int poziceY = 0;
    
    srand(time(NULL));

    char mapa[5][5];

    for(int i=0; i<5;i++){
        for(int j=0; j<5;j++){
            mapa[i][j] = '~';
        }
    }
    
    int hracX = 0;
    int hracY = 0;
    int pokladX = rand() % 5;
    int pokladY = rand() % 5;
    mapa[hracX][hracY] = 'P';
    int utes1X = rand() % 5;
    int utes1Y = rand() % 5;
    int utes2X = rand() % 5;
    int utes2Y = rand() % 5;
    int utes3X = rand() % 5;
    int utes3Y = rand() % 5;
    while((utes1X == pokladX && utes1Y == pokladY) || (utes2X == pokladX && utes2Y == pokladY) || (utes3X == pokladX && utes3Y == pokladY) || (utes1X == hracX && utes1Y == hracY) || (utes2X == hracX && utes2Y == hracY) || (utes3X == hracX && utes3Y == hracY) ||
    (utes1X == utes2X && utes1Y == utes2Y) || (utes1X == utes3X && utes1Y == utes3Y) || (utes2X == utes3X && utes2Y == utes3Y)) {

        utes1X = rand() % 5;
        utes1Y = rand() % 5;
        utes2X = rand() % 5;
        utes2Y = rand() % 5;
        utes3X = rand() % 5;
        utes3Y = rand() % 5;

    }
    mapa[utes1X][utes1Y] = 'X';
    mapa[utes2X][utes2Y] = 'X';
    mapa[utes3X][utes3Y] = 'X';
    mapa[pokladX][pokladY] = 'K';

    for(int i=0; i<5;i++){
        for(int j=0; j<5;j++){
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }

    while(zivoty > 0){
        int pohybX, pohybY;
        printf("Zadejte pozici X (0-4): ");
        scanf("%d", &pohybX);
        printf("Zadejte pozici Y (0-4): ");
        scanf("%d", &pohybY);

        if(pohybX < 0 || pohybX > 4 || pohybY < 0 || pohybY > 4){
            printf("Neplatna pozice! Zkuste znovu.\n");
            continue;
        }

        if(mapa[pohybX][pohybY] == 'K'){
            printf("Gratulujeme! Nasli jste poklad!\n");
            break;
        } else if(mapa[pohybX][pohybY] == 'X'){
            zivoty -= 2;
            printf("Narazili jste na utes! Ztratili jste 2 zivoty. Zivoty: %d\n", zivoty);
        } else {
            printf("Nic zde neni. Ztratili jste 1 zivot za pokus. Zivoty: %d\n", zivoty);
            zivoty -= 1;
        }

        mapa[hracX][hracY] = 'P';
        
        for(int i=0; i<5;i++){
            for(int j=0; j<5;j++){
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
    }
}