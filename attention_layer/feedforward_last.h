#ifndef MODULLE_FF_LAST_H
#define MODULLE_FF_LAST_H
#include "TNN_5_2.h"
void feedforward_last(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[NUM_LABELS], fp2 (*w1)[EMBEDDING_DIM], fp2* b1, int n, int k, int s);

#endif
