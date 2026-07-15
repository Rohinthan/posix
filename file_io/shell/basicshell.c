#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main() {
	char input[100];
	char *args[10];

	while (1) {
	   write(1, "mysh> ", 6);

	   int n = read(0, input, 100);
	   input[n - 1] = '\0'; //remove new line


	   int i = 0;
	   args[i] = strtok(input, " ");
	   while (args[i] != NULL) {
		i++;
		args[i] = strtok(NULL, " ");
	   }

	   int pid = fork();


	   if (pid == 0) {
		execvp(args[0], args);
		write(1, "Command failed\n", 15);
	   } else {
		wait(NULL);
	   }
	}

	return 0;
}

/* its like a shell to get from the file execution

its like a basic shell //

so its support

1 -> ls
2 -> ls -l
3 -> echo hello
4 -> date

*/
