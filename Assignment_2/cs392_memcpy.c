//
// I pledge my honor that I have abided by the Stevens Honor System. - Brereton Conway
#include <stdio.h>

void * cs392_memcpy ( void * dst, void * src, unsigned num){
    char* dst_tmp = (char*)dst;
    char* src_tmp = (char*)src;
    for(int i = 0; i < num; i++){
        dst_tmp[i] = src_tmp[i];
    }
    return dst;
}
