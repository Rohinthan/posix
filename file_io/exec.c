// Run ls from C
// exec() =  turn that process into something else

#include <unistd.h>
#include <stdio.h>

int main() {
	execl("/bin/ls", "ls", NULL);


	printf("This runs only if exec fails\n");
	return 0;

}


/*

structure

int execl(const char *path, const char *arg0, ..., NULL);

Arguments

execl("/bin/ls", "ls", NULL);



Part		Meaning

/bin/ls		Program path

"ls"		program name (arg0)

NULL		end of arguments 


 what happen

* your program starts

* exec() run the /bin/ls

* our program is replaced

* you see directory listing

* And, your code after exec() will NOT run

*/
