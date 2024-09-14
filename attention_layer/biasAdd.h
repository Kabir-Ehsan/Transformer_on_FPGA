#include "activation.h"
#include "TNN_5_2.h"

#ifndef MODULE_BIAS_ADD_H
#define MODULE_BIAS_ADD_H

//void biasAdd(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 *bq, fp2 *bk, fp2 *bv, int n, int d, int t);

void biasAdd(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 *bq, fp2 *bk, fp2 *bv, int n, int d, int t, int factor);
void biasAdd2(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d);
void biasAdd3(fp3 (*qq)[HIDDEN_DIM], fp2 *bq, int n, int d);
void biasAdd4(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d);





#endif
