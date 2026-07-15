#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char input[100];

    while (1) {
        write(1, "mysh> ", 6);
        int n = read(0, input, 100);
        input[n - 1] = '\0';

        char *cmd1 = strtok(input, "|");
        char *cmd2 = strtok(NULL, "|");

        if (cmd2 == NULL) {
            // no pipe
            char *args[10];
            int i = 0;

            args[i] = strtok(cmd1, " ");
            while (args[i] != NULL) {
                i++;
                args[i] = strtok(NULL, " ");
            }

            if (fork() == 0) {
                execvp(args[0], args);
            } else {
                wait(NULL);
            }
        } else {
            // with pipe
            int fd[2];
            pipe(fd);

            if (fork() == 0) {
                // first command
                dup2(fd[1], 1);
                close(fd[0]);
                close(fd[1]);

                char *args[10];
                int i = 0;
                args[i] = strtok(cmd1, " ");
                while (args[i] != NULL) {
                    i++;
                    args[i] = strtok(NULL, " ");
                }

                execvp(args[0], args);
            }

            if (fork() == 0) {
                // second command
                dup2(fd[0], 0);
                close(fd[1]);
                close(fd[0]);

                char *args[10];
                int i = 0;
                args[i] = strtok(cmd2, " ");
                while (args[i] != NULL) {
                    i++;
                    args[i] = strtok(NULL, " ");
                }

                execvp(args[0], args);
            }

            close(fd[0]);
            close(fd[1]);

            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}

/* now this like a shell behaviour so its suppports 

* Normal Commands
* Arguments
* pipes


try 

ls | wc
ls | grep .c
echo hello | wc


*/
