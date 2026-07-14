#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	dup2(fd, 1); // redirect stdout -> file 

	write(1, "Hello file via dup2\n", 21);

	close(fd);
	return 0;
}




/* Core idea
	dup2(old_fd, new_fd);

it says : new_fd behave like old_fd


simple idea --

Before

stdout (1) -> terminal

After
stdio (1) -> file / pipe / something else

What happens ?

normally -->

	write --> terminal

Now -->

	write -->  out.txt


*/
