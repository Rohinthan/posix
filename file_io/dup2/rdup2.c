// realworld example

#include <unistd.h>
#include <sys/wait.h>

int main() {
	int fd[2];
	pipe(fd);

	int pid1 = fork();

	if (pid1 == 0) {
	   //First child --> ls
	   dup2(fd[1], 1); // stdout  --> pipe
	   close(fd[0]);
	   execl("/bin/ls", "ls", NULL);

	}

	int pid2 = fork();

	if (pid2 == 0) {
	    //Second Child -->wc
	    dup2(fd[0], 0); // stdin <-- pipe
	    close(fd[1]);
	    execl("/usr/bin/wc", "wc", NULL);

	}

	// parent

	close(fd[0]);
	close(fd[1]);

	wait(NULL);
	wait(NULL);

	return 0;
}


/* work flow

ls (child 1)

    |

  [ pipe ]

wc (child 2)


important Concepts

*  dup2(fd[1], 1)  -  redirect stdout to pipe

*  dup2(fd[0], 0)  -  redirect stdim from pipe

 ---- remember ----

this call block

your block 1 can  your 1 st block

int pid1 i fill later
*/
