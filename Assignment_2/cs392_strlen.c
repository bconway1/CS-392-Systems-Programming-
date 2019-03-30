//
// I pledge my honor that I have abided by the Stevens Honor System. - Brereton Conway
//
#include <stdio.h>

unsigned cs392_strlen(char *str){
    unsigned int length = 0;
    char end_char = '\0';

    if(str == NULL){
        return length;
    }
    if(str == '\0'){
        return length;
    }
    while(str[length] != '\0'){
        length++;
    }
    return length;
}
