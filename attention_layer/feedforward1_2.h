#ifndef MODULLE_FF1_H
#define MODULLE_FF1_H
#include "TNN_5_2.h"

void feedforward1(fp1 (*in)[fact6], fp3 (*out)[EMBEDDING_DIM], fp2 (*w1)[fact6], int *index, int s, int n, int k);

#endif
