#include <stdio.h>
#include <stdlib.h>

int falseFunc(char a, int times);
void trueFunc();

typedef int (* FalseFunc_t) (char p1, int p2);
typedef void (* TrueFunc_t) (void);

int falseFunc(char a, int times){
	int i;
	fprintf(stdout, (const char *) "Condition False\n");
	for (i = 0; i < times; i++){
		fprintf(stdout, (const char *)"Char %c printed %d times.\n", a, i+1);
	}
	return 0;
}

void trueFunc(){
	fprintf(stdout, (const char *) "True Function\n");
	fprintf(stdout, (const char *) "Empty function\n");
}

int main(){
	int someNumber;
	FalseFunc_t falseCall = falseFunc;
	TrueFunc_t trueCall = trueFunc;

	fprintf(stdout, (const char *) "Give a number: ");
	fscanf(stdin, "%d", &someNumber);

	if(someNumber < 10) trueCall();
	else falseCall('a', 2);

	return 0;
}
