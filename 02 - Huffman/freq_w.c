#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "freq_w.h"

#define NAO_FIM 1

int *freq_w(FILE *f)
{
    setlocale(LC_ALL,"");

    unsigned char x;
	int i;
	int *countsort;

    countsort = (int*)malloc(256*sizeof(int));
    for (i = 0; i < 256; i++)
    {
		countsort[i] = 0;
	}
    while(NAO_FIM)
    {
		x = fgetc(f);
        if(feof(f))
        {
			break;
		}
		countsort[x]++;
	}
	return countsort;
}
