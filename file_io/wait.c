#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>   // ---> its header for wait function

int main () {
	int pid = fork();

	if (pid == 0) {
	   execl("/bin/ls", "ls", NULL);
	} else {
	   wait(NULL);
	   printf("Child Finished\n");
	}

	return 0;
}

/* what happen the parent waits wntil the child finishes

so output becomes order.

Structure

pid_t wait(int * status);

--> waits for child

--> collects exit status


----------------------------------


Now you understand how the shell works:


User types command
	|
fork()
	|
child -> exec(command)
	|
parent -> wait()


-----------------------------------
*/
