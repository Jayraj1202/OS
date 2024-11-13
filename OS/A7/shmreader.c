#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{

//ftok to generate unique key
key_t key=ftok("shmfile",65);

//shmget returns identifier
int shmid=shmget(key,1024,066|IPC_CREAT);

//shmat to attach to shared memmory
char *str=(char*) shmat(shmid,(void*)0,0);

printf("Data read from memory:%s\n",str);

//detach
shmdt(str);

//destroy
shmctl(shmid,IPC_RMID,NULL);
return 0;


}
