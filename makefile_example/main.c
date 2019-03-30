#include<stdio.h>
#include "sum.h"


int main(int argc, char** argv){

	int a, b, c, d;

	printf("Please input three integers:\n");

	scanf("%d%d%d", &a, &b, &c);

	d = add_3_num(a, b, c);

	printf("The summation of a, b, and c is %d\n", d);

	return 1;
}
