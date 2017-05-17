#include "bitop.h"

int setBit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

int isBitISet(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}
