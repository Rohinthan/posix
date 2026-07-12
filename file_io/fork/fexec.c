// fork() + exec()

#include <stdio.h>
#include <unistd.h>

int main() {
	int pid = fork();

	if (pid == 0) {
	   //child
	   execl("/bin/ls", "ls", NULL);
	} else {
	   //parent
	   printf("Parent running\n");
	}

	return 0;
}


/* work flow :

1 fork() --> creats child

2 Child  --> becomes ls

3 Parent --> continues

Now you have parallel behaviour

problem here :

Parent may finish before child

so use wait() its come next  */
