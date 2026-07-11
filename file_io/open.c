#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);

	write(fd, "Hello File\n", 11);

	close(fd);
	return 0;
}

/*


 structure :

int open(const char * pathname, int flags, mode_t mode);


Argument 1 --> test.txt

file name ;

	if file exists --> open it
	if not --> depends on flags

Argument 2 --> O_CREAT | WROLY  flag arguments

Flags			meaning

O_CREAT			Create file if not exist

O_WRONLY 		write only

O_RDONLY		Read only

O_RDWR			Read + Write

O_TRUNC			Create file

O_APPEND		Append at end


Argument 3 --> 0064


file permission


Owner:  Read + Write = 6

Group:  Read = 4

Others: Read = 4

In bash

rw-r--r--

fd  ==> file Descriptor

ex : fd = 3 (example)

Because:

0 --> stdin
1 --> stdout
2 --> stderr
3+ -> files

	write(fd, " hello file\n", 11);

right in ->  inside of the file not ur terminal  |  11 means the character count because the write does not detect char or string directly 

	close(fd);

release resource and prevent memeory if not do memeory can leak like water in the bucket and causes user memory like you destroy ur own system for no reason 

*/







