// Process Communication
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd[2];
	pipe(fd);

	int pid = fork();

	if (pid == 0) {
		//Child
		close(fd[1]);  //close write end

		char buffer[20];
		int n = read(fd[0], buffer, 20);
		write(1, buffer, n);
	} else {
		//Parent
		close(fd[0]);  //close read end

		write(fd[1], "Hello from parent\n", 18);
	}

	return 0;
}

/*

Core Idea

process A ---> Process B
	(pipe)

* One writes * One read

syntax

int pipe(int fd[2]);

after calling 

fd[0] --> read end
fd[1] --> write end



Flow

1 - pipe(fd) --> create pipe

2 - fork()  --> split process

now the work was

Parent

    * writes into fd[1]

child

    * reads from fd[0]

*/
