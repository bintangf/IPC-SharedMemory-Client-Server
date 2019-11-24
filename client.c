#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE     27

int main()
{
    int shmid1,shmid2;
    key_t key1,key2;
    char *type;
    int *buy;

    key1=5678;
    key2=8765;

    shmid1=shmget(key1, MAXSIZE, IPC_CREAT | 0666);
    shmid2=shmget(key2, MAXSIZE, IPC_CREAT | 0666);

    type=shmat(shmid1, NULL, 0); 
    buy=shmat(shmid2, NULL, 0);

    printf("Welcome to Bluejack Smartphone\n\n");
    printf("          Client\n");
    printf("==============================\n\n");
    do{
    	printf("Input your phone type [Nokia, Samsung, Apple] [\"exit\" to close this program] : ");
    	scanf("%s",type);
    	if(strcmp("exit",type) == 0){
       		exit(0);
    	};
    }while(strcmp("nokia",type) != 0 && strcmp("samsung",type) != 0 && strcmp("apple",type) != 0);
    do{
    	printf("Input how many phone you want to buy [1..8] : ");
    	scanf("%d",buy);
    }while(*buy<1||*buy>8);

    exit(0);
}

