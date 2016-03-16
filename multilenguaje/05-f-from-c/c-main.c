
#include <stdio.h>

#define NUM 200

/* agrego *suma */
extern void sum_abs_(int *inp, int *num, int *suma);

int main(int argc, char **argv)
{
    int data[NUM], num, i, suma=0;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }
/* sum_abs_ va afuera del print */
	sum_abs_(data, &num, &suma);
    printf("sum=%d\n", suma);
    return 0;
}
