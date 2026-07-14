//dup2 example 1

#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	dup2(fd, 1); //stdout --> file

	execl("/bin/ls", "ls", NULL);

	return 0;
}

/*

Run --> no output on terminal

Check file --> contains ls output

*/
