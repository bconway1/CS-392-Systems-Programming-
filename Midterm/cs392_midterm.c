#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cs392_midterm.h"

int test_cs392_strcpy(){

	char src[200];
	char dest[200];
	char index[] = {30, 60, 90, 120, 150};
	int test_index;
	char tmp_index;

	int success;
	success = 0;

	for(test_index = 0; test_index < 4; test_index++){

		memset(dest, 1, 200);
		memset(src, 1, 200);

		for(tmp_index = 0; tmp_index < index[test_index]; tmp_index++){
			int val = rand();

			val += (val == 0 ? 1 : 0);

			if(val)
				src[tmp_index] = (char)val; 
		}
	
		src[tmp_index] = '\0';

		cs392_strcpy(dest, src);

		if(strcmp(dest, src) == 0)
			success++;
	}
	return success;
}


int test_cs392_strcmp(){
	
	int success = 0;
	char src[200];
	char dest[200];
	
	int index;

	int res1; 
	int res2; 

	for(index = 0; index < 30; index++){

		int val = rand();
		val += (val == 0 ? 1 : 0);
		src[index] = dest[index] = val;	
	}
	
	src[index] = dest[index] = 0;
	
	
	res1 = cs392_strcmp(src, dest);
	res2 = strcmp(src, dest);
	if (res1 == res2 || res1 * res2)
		success++;
	

	for(index = 0; index < 60; index++){
		int val = rand() % 128;
		val += (val == 0 ? 1 : 0);
		src[index] = val;
	
		val = rand() % 128;
		val += (val == 0 ? 1 : 0);
		dest[index] = val;
	}

	src[index] = dest[index] = 0;
		
	res1 = cs392_strcmp(src, dest);
	res2 = strcmp(src, dest);
	if (res1 == res2 || res1 * res2)
		success++;
	
	for(index = 0; index < 90; index++){
		int val = rand() % 256;
		val += (val == 0 ? 1 : 0);
		src[index] = val;
	
		val = rand() % 256;
		val += (val == 0 ? 1 : 0);
		dest[index] = val;
	}

	src[index] = dest[index] = 0;

	res1 = cs392_strcmp(src, dest);
	res2 = strcmp(src, dest);
	if (res1 == res2 || res1 * res2)
		success++;
	
	for(index = 0; index < 120; index++){
		int val = rand() % 128;
		val += (val == 0 ? 1 : 0);
		src[index] = dest[index] = val;
		
	}
	src[index] = dest[index] = 0;

	dest[100] = 0; 

	res1 = cs392_strcmp(src, dest);
	res2 = strcmp(src, dest);
	if (res1 == res2 || res1 * res2)
		success++;
	
	return success; 	
	
}


int test_cs392_strncat(){
	
	int success = 0;
	char src[200];
	char dest1[200];
	char dest2[200];	

	int index;

	for(index = 0; index < 30; index++){
		int val = rand();
		val += (val == 0 ? 1 : 0);
		src[index] = dest1[index] = dest2[index] = val;	
	}
	
	src[index] = dest1[index] = dest2[index] = 0;	

	cs392_strncat(dest1, src, 25);	
	strncat(dest2, src, 25);
	
	if (strcmp(dest1, dest2) == 0)
		success++;
	

	for(index = 0; index < 30; index++){

		int val = rand();
		val += (val == 0 ? 1 : 0);
		src[index] = dest1[index] = dest2[index] = val;	
	}
			
	
		src[index] = dest1[index] = dest2[index] = 0;	

	cs392_strncat(dest1, src, 50);	
	strncat(dest2, src, 50);
	
	if (strcmp(dest1, dest2) == 0)
		success++;
	
	return success; 	
	
}



int main(int argc, char** argv){

	printf("-------- Hello, welcome to the CS392 midterm exam ----------- \n");
	
	printf("You passed \x1B[31m %d \x1B[37m test cases for cs392_strcpy\n", test_cs392_strcpy());

	printf("You passed \x1B[31m %d \x1B[37m test cases for cs392_strcmp\n", test_cs392_strcmp());

	printf("You passed \x1B[31m %d \x1B[37m test cases for cs392_strncat\n", test_cs392_strncat());
	printf("Have a nice day\n");

}

