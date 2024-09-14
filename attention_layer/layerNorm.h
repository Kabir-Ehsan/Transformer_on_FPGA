#ifndef MODULE_LAYER_NORM_H
#define MODULE_LAYER_NORM_H
#include "TNN_5_2.h"
void layerNorm(fp1 (*x)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2* gamma, fp2* beta, fp1 *eps, int seq, int embed);

#endif
