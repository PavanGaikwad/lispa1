#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv){
	
	/*print version and exit information*/
	printf("lispa1 version 0.0.0.1\n");
	printf("Press cntrl+c to exit.\n");

	while(1){
	char* input = readline("lispa1> ");
	
	/* add the user input to history so it is avalible via the 'up' arrow key.*/
	add_history(input);
	
	/* readline function strips the trailing /n, so we add it to our print function*/
	printf("You entered %s\n", input);

	/* we have moved from fgets to readline. When fgets gets called, it uses the existing buffer, readline, however allocates new memory when it is called. We need to free this.*/		
	free(input);
	}
	return 0;
}
