#ifndef MODULE_LOAD_IN_H
#define MODULE_LOAD_IN_H
#include "TNN_5_2.h"
using namespace std;
//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8,  fp1 *x9, fp1 *x10, fp1 *x11, fp1 *x12, fp1 *in_stream, int *index, int seq_out, int tile); //fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8,
//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, fp1 *x9, fp1 *x10, fp1 *in_stream, int *index, int seq_out, int tile);
//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, fp1 *x9, fp1 *x10, fp1 *x11, fp1 *x12, fp2 *in_stream, int *index, int seq_out, int tile, int factor); //fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8,
//


//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp2 *in_stream, int *index, int seq_out, int tile, int factor);
//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp2 *in_stream, int *index, int seq_out, int tile, int factor);
void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, fp2 *in_stream, int *index, int seq_out, int tile, int factor);
void loadIn2(fp2 (*x1)[fact6], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor);
void loadIn3(fp3 (*x1)[fact6], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor);

//void loadIn2(fp2 (*x1)[EMBEDDING_DIM], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor);
//void loadIn3(fp3 (*x1)[fact1], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor);
//void loadIn3(fp3 (*x1)[EMBEDDING_DIM], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor);


#endif
