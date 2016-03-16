#include <stdlib.h>
#include "c-sum.h"

// tomo punteros
int sum_abs_(int *ent, int *num, int *asum) {
   int i;
   for (i=0,*asum=0; i < *num; ++i) {
       *asum += abs(ent[i]); 
   }
   return 0;
}
