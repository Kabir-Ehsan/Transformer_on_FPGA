#ifndef MODULE_LOAD_WO_H
#define MODULE_LOAD_WO_H
#include "TNN_5.h"
void loadWo(fp2 (*wo1)[EMBEDDING_DIM/NUM_HEADS], fp2 *weight_stream1, int *index, int embed_out, int nheads_out);


#endif
