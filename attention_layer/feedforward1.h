#ifndef MODULLE_FF1_H
#define MODULLE_FF1_H
#include "TNN_5.h"

//void feedforward1(fp1 (*in)[fact1], fp3 (*out)[EMBEDDING_DIM], fp2 (*w1)[fact1], int *index, int s, int n, int k);

void feedforward1(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2 (*w1)[EMBEDDING_DIM], int *index, int s, int n, int k);

#endif
