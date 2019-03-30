//
// I pledge my honor that I have abided by the Stevens Honor System - Brereton Conway
//

#include <stdio.h>

int cs392_strcmp(char *s1, char *s2){
    int i = 0;
    while(1) {
        if (s1[i] == s2[i]) {
            if(s1[i] == '\0') return 0;

        }

        else if(s1[i] > s2[i]){
            return 1;
        }
        else if(s1[i] < s2[i]){
            return -1;
        }
        i++;
    }
}