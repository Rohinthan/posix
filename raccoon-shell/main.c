#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>

#define INPUT_SIZE 1024

int main(void) {
   char input[INPUT_SIZE];

   while(1) {
      write(STDOUT_FILENO, "raccoon$", 9);

      if(fgets(input, sizeof(input), stdin) == NULL) {
	 break;
      }

      input[strcspn(input, "\n")] = '\0';

      if (strcmp(input, "exit") == 0) {
	  break;
      }

      if (input[0] == '\0') {
  	  continue;
      }

      if (strncmp(input, "cd", 2) == 0 &&(input[2] == '\0' || ' ' || input[2] == '\t')) {

	 char *path = input + 2;

	 while (*path == ' ' || *path =='\t'){
	     path++;
	 }

	 if (*path == '\0') {
	    fprintf(stderr, "cd: mission directory\n");
	 } else if (chdir(path) == -1) {
  	    perror("cd");
	 }

	 continue;
    }

    pid_t pid = fork();


      if (pid < 0) {
	   perror("fork");
	   continue;
      }

      if (pid == 0) {
	  char *args[64];
  	  int i = 0;

	  char *token = strtok(input, " \t\r\n");

	  while (token != NULL && i < 63) {
	      args[i++] = token;
	      token = strtok(NULL, " \t\r\n");
	  }


	  args[i] = NULL;


	  execvp(args[0], args);
 	  perror("execvp");
	  _exit(127);

      }

      int status;

      while (waitpid(pid, &status, 0) < 0) {
	  perror("waitpid");
	  break;
      }

   }

   return 0;
}
