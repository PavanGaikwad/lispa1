#include <stdio.h>

static char input[2048];

int main(int argc, char** argv){

	/*print version and Exit Information*/

	puts("Lispa1 version 0.0.0.1\n");
	puts("Press cntrl+c to exit.\n");

	while(1){
	
	fputs("lispa1 $>", stdout);

	fgets(input, 2048, stdin);

	printf("No you're a %s", input);
	}
	
	return 0;
}
