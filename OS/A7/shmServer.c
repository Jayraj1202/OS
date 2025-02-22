//writer process
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	//ftok to generate unique key
	key_t key=ftok("shmfile",65);
	
	//shmget returns identifier in shmid
	//r-4,w-2,x-1 
	int shmid=  shmget(key,1024,0666|IPC_CREAT);
	
	//shmat to attach to shared memory
	char *str=(char*) shmat(shmid,(void*)0,0);
	
	printf("Write Data: ");
	gets(str);
	
	printf("Data written in memory :%s\n",str);
	
	//detach
	shmdt(str);
	return 0;

}
