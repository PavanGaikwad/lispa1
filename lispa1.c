#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv){
	
	/*print version and exit information*/
	printf("lispa1 version 0.0.0.2\n");
	printf("Press cntrl+c to exit.\n");

	/* creating parsers using mpc */
	
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lispa1 = mpc_new("lispa1");
	
	/* defining lang */
	mpca_lang(MPC_LANG_DEFAULT,
	"						   \
	 number   : /-?[0-9]+/ ;	                   \
	 operator : '+' | '-' | '*' | '/' ;                \
	 expr     : <number> | '(' <operator> <expr>+ ')' ; \
   	 lispa1   : /^/ '(' <operator> <expr>+ ')' /$/ | /^/ <number>+ /$/ ;     \
	",Number, Operator, Expr, Lispa1);


	while(1){
	char* input = readline("lispa1> ");
	
	/* add the user input to history so it is avalible via the 'up' arrow key.*/
	add_history(input);

	/* attempt to parse user input */
	mpc_result_t r;
	if(mpc_parse("<stdin>", input , Lispa1, &r)){
	/* on success print and delete AST  */
	mpc_ast_print(r.output);
	mpc_ast_delete(r.output);
	}else{
	mpc_err_print(r.error);
	mpc_err_delete(r.error);
	}

	
	/* readline function strips the trailing /n, so we add it to our print function*/
/*	printf("You entered %s\n", input);*/

	/* we have moved from fgets to readline. When fgets gets called, it uses the existing buffer, readline, however allocates new memory when it is called. We need to free this.*/		
	free(input);
	}
	mpc_cleanup(4, Number, Operator, Expr, Lispa1);
	return 0;
}
