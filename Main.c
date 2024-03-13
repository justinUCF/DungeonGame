#include <stdio.h>
#include <stdlib.h>

int allocatedMemory = 0;

char menuSelectText[] = "\n------------------\n^^^Dungeon-RPG^^^\n------------------\n0. Exit\n1. New Save\n2. Load Save\n------------------\n";

typedef struct playerStats{
    int healthPoints;
    int attackDamage;
    int damagetaken;
}playerStats;

playerStats* initializePlayerStats(int healthPoints, int attackDamage){
    //Allocates space in mem for playerStats
    playerStats* playerStat = (playerStats*)malloc(sizeof(playerStats));
    if(playerStat == NULL){
        printf("ERROR: initializePlayerStats() failed"); 
        return NULL;
    }
    else{
        allocatedMemory += sizeof(playerStats);
    }
    //Initialize playerStats values
    playerStat->healthPoints = healthPoints;
    playerStat->attackDamage = attackDamage;
    playerStat->damagetaken = 0;
    //return address of playerStats
    return playerStat;
}

void freePlayerStats(playerStats* playerStat){
    if(playerStat == NULL) return;
    free(playerStat);
    allocatedMemory -= sizeof(playerStats);
    return;
}

int requestInput(){
    int inputNum = 0;
    printf();
    scanf("%d", &inputNum);
    return inputNum;
}

void mainMenu(){
    printf("%s", menuSelectText);
    int option = requestInput();
    return;
}



int main(){
    mainMenu();
    printf("\n\nMEMORY LEAKED: %d bytes.", allocatedMemory);
    return 0;
}