#ifndef MODULE_ADDNORM_H
#define MODULE_ADDNORM_H
#include "TNN_5.h"
//void addNorm1(fp3 (*ff_out1)[EMBEDDING_DIM], fp1 *x1, int seq_out, int embed_out);

void addNorm1(fp3 (*ff_out1)[EMBEDDING_DIM], fp1 (*x1)[EMBEDDING_DIM], int seq_out, int embed_out);


#endif
