#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

main()
{
	int shmid;
	key_t key;
	char *shm, *s;
	FILE *fptr;

	fptr=fopen("digits.out","w");    //Write mode so that previous contents are removed
	key = 888; // Random key 888 to identify the shared memory location
	shmid = shmget(key, 27, 0666);  //locate the segment
	shm = shmat(shmid, NULL, 0);   //attach segment to data space
	while(1)//infinite loop
		{
		fptr=fopen("digits.out","a"); 
		int count=0; //Keeps track of the number of digits
		char copy[300]; //temporary location
		for (s = shm; *s !='\0'; s++) 
			{
			if (*s=='\n') //We don't want a new line between the line and the digit count
				fprintf(fptr,"  --->"); 
			else	
				putc(*s,fptr); //Print current character onto the output file
			if (*s=='1'||*s=='2'||*s=='3'||*s=='4'||*s=='5'||*s=='6'||*s=='7'||*s=='8'||*s=='9'||*s=='0')
				count++;
			}
		fprintf(fptr,"%d\n",count); //Print count value next to the line in the file
		strcpy(copy,shm); 
		fclose(fptr); 
		point1:
		//Do nothing until new line is entered (value at shared memory location is changed)
		if (strcmp(copy,shm)==0)  
			goto point1;
		}
 
}
