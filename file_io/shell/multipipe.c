#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX 10

int main() {
    char input[200];

    while (1) {
        write(1, "mysh> ", 6);

        int n = read(0, input, 200);
        input[n - 1] = '\0';

        // split by '|'
        char *commands[MAX];
        int num_cmds = 0;

        char *token = strtok(input, "|");
        while (token != NULL) {
            commands[num_cmds++] = token;
            token = strtok(NULL, "|");
        }

        int prev_fd = -1;

        for (int i = 0; i < num_cmds; i++) {
            int fd[2];

            if (i < num_cmds - 1) {
                pipe(fd);
            }

            if (fork() == 0) {
                // input from previous pipe
                if (prev_fd != -1) {
                    dup2(prev_fd, 0);
                    close(prev_fd);
                }

                // output to next pipe
                if (i < num_cmds - 1) {
                    dup2(fd[1], 1);
                    close(fd[0]);
                    close(fd[1]);
                }

                // parse arguments
                char *args[10];
                int j = 0;

                args[j] = strtok(commands[i], " ");
                while (args[j] != NULL) {
                    j++;
                    args[j] = strtok(NULL, " ");
                }

                execvp(args[0], args);
                write(1, "exec failed\n", 12);
                exit(1);
            }

            // parent
            if (prev_fd != -1) {
                close(prev_fd);
            }

            if (i < num_cmds - 1) {
                close(fd[1]);
                prev_fd = fd[0];
            }
        }

        // wait for all children
        for (int i = 0; i < num_cmds; i++) {
            wait(NULL);
        }
    }

    return 0;
}


/*

ls | wc
ls | grep .c | wc
ps | grep bash | wc
echo hello world | wc

try this command 

cat file.txt | grep hello | wc > out.txt &


*/
