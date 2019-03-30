int add_2_num(int a, int b){
	return a + b;
}

int add_3_num(int a, int b, int c){
	return add_2_num(add_2_num(a, b), c);
}
