#ifndef MODULE_SOFTMAX_H
#define MODULE_SOFTMAX_H
#include "TNN_5_2.h"
//void softmax(fp1 (*x)[EMBEDDING_DIM/NUM_HEADS], int n, int d, int t);
void softmax(fp1 (*x)[SEQ_LEN], int n, int d, int t);

#endif
