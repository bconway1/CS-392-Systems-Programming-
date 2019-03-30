#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "cs392_string.h"


void test_memcpy(){

	int src[20];
	int dst[20];
	int index = 0 ; 

	while(index < 20)
		src[index++] = rand();

	cs392_memcpy(dst, src, 20*sizeof(int));

	if(memcmp(src, dst, 20*sizeof(int)) == 0)
		printf("Congratulations, you passed the memcpy task\n");
	else
		printf("Sorry, you did not pass the memcpy task. Please try again\n");
		
}

void test_strlen(){

	char str[100];
	int randloc = 0;
	int len = 0 ;

	randloc =  rand() % 100;

	memset(str, 'A', 100);
	
	str[randloc] = 0;

	len = cs392_strlen(str);
	
	if(len == randloc)
                printf("Congratulations, you passed the strlen task\n");
        else
                printf("Sorry, you did not pass the strlen task. Please try again\n");

}

int main(int argc, char** argv){
		
	test_memcpy();
	test_strlen();
	
}

