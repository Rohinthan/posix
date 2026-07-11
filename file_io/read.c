#include <unistd.h>

int main() {
	char buffer[20];

	int n = read(0, buffer[20]);
	write(1, buffer, n);

	return 0;
}


/* 

structure 


ssize_t read(int fd,void *buf, size_t count);


argument 1 -> 0

read( 0, ...)  -- take input from keyboard

argument 2 -> buffer

buffer buffer input will stored ( memory location)

argument 3 -> 20

maximm number of bytes to read



when you run the program 

* wait for input'
* typing something,
* enter,
* it continues.


write(1 , buffer, 20); print whatever is inside the  buffer 

but careful it print fill of 20 bytes , nit what you typed
*/
