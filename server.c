#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE     27

int main()
{
    int shmid1,shmid2;
    key_t key1,key2;
    char *type;
    int *buy;
    int price;

    key1=5678;
    key2=8765;

    shmid1=shmget(key1, MAXSIZE, IPC_CREAT | 0666);
    shmid2=shmget(key2, MAXSIZE, IPC_CREAT | 0666);

    type=shmat(shmid1, NULL, 0);  
    buy=shmat(shmid2, NULL, 0);

    printf("Welcome to Bluejack Smartphone\n");
    printf("          Server\n");
    printf("==============================\n");
    printf("Your phone type is                : %s\n",type);
    printf("The aomunt of phone you bought is : %d\n",*buy);
    srand (time(NULL));
    printf("Per unit price is                 : %d\n",price=rand() % (7000000 + 1 - 5000000) + 5000000);
    printf("Total price you must pay this     : %d\n",*buy*price);

    exit(0);
}
