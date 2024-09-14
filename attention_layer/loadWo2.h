#ifndef MODULE_LOAD_WO_H
#define MODULE_LOAD_WO_H
#include "TNN_5_2.h"

void loadWo(fp2 (*wo1)[fact6], fp2 *weight_stream1, int *index, int embed_out, int nheads_out, int factor);

//void loadWo(fp2 (*wo1)[EMBEDDING_DIM], fp2 *weight_stream1, int *index, int embed_out, int nheads_out, int factor);


#endif
