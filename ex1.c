#include "ex1.h"
#include <stdio.h>

int is_big_endian(){
    long x = 1;
    if(*(char *)&x == 1) {
        return 0;
    }
    return 1;
}

unsigned long merge_bytes(unsigned long x, unsigned long int y){
    long half_x, half_y;
    if (is_big_endian()) {
        half_x = x&0x00000000ffffffff;
        half_y = y&0xffffffff00000000;
    } else {
        half_x = x&0xffffffff00000000;
        half_y = y&0x00000000ffffffff;
    }
    long merge = half_x+half_y;
    return merge;
}

unsigned long put_byte(unsigned long x, unsigned char b, int i){
    if (!is_big_endian()) {
        i = sizeof(unsigned long) - i - 1;
    }
    char * c = &x;
    c += i;
    *c = b;
    return x;
}