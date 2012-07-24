//pgm to illusrtat fork();

#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>

void child(int n)
{	int fact=1;	
	printf("\nControl reached the child process");
	printf("\nThis is the child process with PID %d and ParentPID %d:",getpid(),getppid());
	
	

	printf("\nsquare of the number is :%d",n*n);
	printf("\nChild Terminates here\n");
		
	
}
void parent()
{	printf("\t This is the parent process with PID %d and ParentPID %d:",getpid(),getppid());
	printf("\ncontrol Returned to Parent"); 
	wait(NULL);
	printf("\nParent Terminates here \n\n");
}

void  main()
{
	int pid,num;

	printf("\nEnter a number :");
	scanf("%d",&num);
	
	pid=fork();  
        if (pid!=0)	// pid is non-zero, so parent
        {	parent();	
	}
        else	//pid is zero, so child.
        {       child(num);
        }
}

