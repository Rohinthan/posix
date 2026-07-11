//deeper then fork

#include <stdio.h>
#include <unistd.h>

int main() {
	int pid = fork();

	if (pid == 0) {
	   printf("Child process\n");
	} else {
	   printf("Parent process\n");
	}

	return 0;
}

/* what theh different 

Return Value of fork()

return value 		Meaning

0			Child process   <---

>0			Parent (Child PID)

-1			Error



Output be like

Parent process
Child process


but look the print function i wrote child and parent but belike  < - > < -- > ? switching there position

after the fork()

both process are run independently

then

* have separate memory
* run same code
* but take different paths



*/





