#ifndef MODULE_SELF_ATTENTION_H
#define MODULE_SELF_ATTENTION_H
#include "TNN_5_2.h"

void self_attention1(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention2(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention3(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention4(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention5(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention6(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention7(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention8(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention9(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention10(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention11(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);
void self_attention12(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor);


#endif
