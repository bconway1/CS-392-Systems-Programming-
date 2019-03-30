//
// I pledge my honor that I have abided by the Stevens Honor System - Brereton Conway
//

#include <stdio.h>


char *cs392_strcpy(char *dest, char *src){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}


