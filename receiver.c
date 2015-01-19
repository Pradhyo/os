#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>


main()
{

	char c;
	int shmid;
	key_t key;
	char *shm;
	key = 888; // Random key 888
	shmid = shmget(key, 27, IPC_CREAT | 0666);// Create the segment
	shm = shmat(shmid, NULL, 0);//attach segment to data space
	printf("Keep entering lines\n");
	while(1)
	{	
	fgets (shm, 256, stdin); //get input from user
	} 
}


