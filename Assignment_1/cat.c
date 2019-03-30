// I pledge my honor that I have abided by the stevens honor system - Brereton Conway

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF_SIZE 100
#define SIZE 1

void output(char* buffer, FILE* fp);
void check_for_errors(char* buffer, FILE* fp);

int main(int argc, char* argv[]) {
    /*make sure there is exactly one file listed*/
    if(argc != 2){
        printf("Error: please specify only one file");
        exit(1);
    }
    /*Declare variables*/
    char* filename = argv[1];
    FILE* fp;
    fp = fopen(filename, "r");
    char* buffer = malloc(BUFF_SIZE);
    /*make sure buffer and file pointer are good*/
    check_for_errors(buffer, fp);
    /*read and print data*/
    output(buffer, fp);
    /*Clean up stream and give back memory*/
    fclose(fp);
    free(buffer);

    return 0;
}

void output(char* buffer, FILE* fp){
    while(1){
        /*read contents of file into buffer*/
        fread(buffer, BUFF_SIZE, SIZE, fp);
        /*check for stream errors*/
        if( ferror(fp) ){
            printf("Cannot open file due to error %d\n", errno);
            break;
        }
        /*print contents of buffer*/
        fprintf(stdout, "%s", buffer);
        /*check for end of the file*/
        if(feof(fp)){
            break;
        }
    }
    return;
}

void check_for_errors(char* buffer, FILE* fp){
    /*if either buffer or fp are NULL then exit; something went wrong*/
    if(buffer == NULL){
        printf("Cannot open file due to memory error\n");
        exit(1);
    }

    if(fp == NULL){
        printf("Cannot open file due to error %d\n", errno);
        exit(1);
    }
}