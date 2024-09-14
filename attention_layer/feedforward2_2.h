#ifndef MODULLE_FF2_H
#define MODULLE_FF2_H
#include "TNN_5_2.h"

//void feedforward2(fp1 (*in)[fact1], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[fact1], int *index, int s, int n, int k);

void feedforward2(fp1 (*in)[fact6], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[fact6], int *index, int s, int n, int k);

#endif
