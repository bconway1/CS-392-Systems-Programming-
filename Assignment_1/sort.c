// I pledge my honor that I have abided by the stevens honor system - Brereton Conway
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "sort.h"


int main(int argc, char* argv[]) {

    check_argc(argc);

    char* inputfile_string = argv[1];
    char* outputfile_string = argv[2];
    char* buffer = malloc(100);

    FILE* input_fp = fopen(inputfile_string, "r");
    FILE* output_fp = fopen(outputfile_string, "wb");
    if((buffer == NULL) || (input_fp == NULL) || (output_fp == NULL)){
        printf("cannot open file\n");
    }

    //get size of input file by counting lines. this will tell us how many ints there are
    int lines = count_lines(input_fp);

    rewind(input_fp);

    //take the ints from the input file and put them into an array of unsigned ints
    unsigned int* int_arr = malloc(sizeof(unsigned int) * lines);
    char s_line[SIZE];
    for(int i = 0; i < lines; i++){
        if(feof(input_fp)){
            break;
        }
        fgets(s_line, 25, input_fp);
        int_arr[i] = (unsigned int)atoi(s_line);

    }
    //sort array
    bubble_sort(int_arr, lines);


    char newline = '\n';

    //input sorted ints into the output file in byte format
    for(int i = 0; i < lines; i++){
        fwrite(&int_arr[i], 1, sizeof(int_arr[i]), output_fp);
        fwrite(&newline, 1, 1, output_fp);
        fflush(output_fp);
        if (ferror(output_fp)) {
            printf("Cannot write to output file due to error %d\n", errno);
            exit(1);
        }

    }

    /*flush and close the streams as well as free memory*/
    fclose(input_fp);
    fflush(output_fp);
    fclose(output_fp);
    free(buffer);
    free(int_arr);

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    /*sort the array of ints in ascending order*/
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int count_lines(FILE* input_fp){
    /*count how many lines are in the input file*/
    char temp;
    int lines = 0;
    //every newline character means 1 line
    while(!feof(input_fp)){
        temp = fgetc(input_fp);
        if(temp == '\n'){
            lines++;
        }
    }
    return lines;
}

void check_argc(int argc){
    /*make sure two files are listed*/
    if(argc != 3){
        printf("please list two files\n");
        exit(1);
    }
}
