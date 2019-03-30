//
// I pledge my honor that I have abided by the Stevens Honor System - Brereton Conway
//
#include <stdio.h>

char *cs392_strncat(char *dest, char *src, unsigned n){
    int dest_count = 0;
    while(dest[dest_count] != '\0'){
        dest_count++;
    }
    int src_count;
    for(src_count = 0;  src_count < n && src[src_count] != '\0'; src_count++){
        dest[dest_count + src_count] = src[src_count];
    }
    dest[dest_count + src_count] = '\0';
    return dest;
}
