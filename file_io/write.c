#include <unistd.h>

int main() {
	write(1, "hello world\n", 12);
	return 0;
}


/* int main()  -- everything start here 

0 - stdin

1 - stdout  --  this for output :

2 - stderr

 ====

12 means the charaters because the write() doesnot detect the  string length 

h e l l o _ w o r  l  d  \n
| | | | | | | | |  |  |  | 
1 2 3 4 5 6 7 8 9 10 11 12


return the function */ 





