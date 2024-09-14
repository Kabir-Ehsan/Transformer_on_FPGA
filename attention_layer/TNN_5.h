//#ifdef TNN_HEADER
//#define TNN_HEADER

#include"stdio.h"
#include"stdlib.h"
#include <iostream>
#include "math.h"

using namespace std;

#include "hls_math.h"
#include "ap_fixed.h"
#include "hls_stream.h"
#include "ap_axi_sdata.h"
#include "assert.h"
#include "ap_int.h"


// Define the input and output sizes


#define BATCH_SIZE 1//8//32
#define SEQ_LEN 64//128//16//2//
#define EMBEDDING_DIM 512//256//64//128//768//4//8//512
#define NUM_HEADS 8//12//2//16//
#define HIDDEN_DIM 4*EMBEDDING_DIM //2048
#define OUTPUT_DIM 1//128//768//530//16//1000

#define NUM_ENCODER_LAYERS 1//4//12//24 //6
#define NUM_DECODER_LAYERS 4//6
#define NUM_LABELS 2
#define TILE_SIZE EMBEDDING_DIM//1//8
//#define epsilon 1*e-12


/*
#define BATCH_SIZE 1//8//32
#define SEQ_LEN 2//2//128
#define EMBEDDING_DIM 4//8//512
#define NUM_HEADS 2//16//8
#define HIDDEN_DIM 4*EMBEDDING_DIM //2048
#define OUTPUT_DIM 530//16//1000

// Define the number of encoder and decoder layers
#define NUM_ENCODER_LAYERS 2//12//24 //6
#define NUM_DECODER_LAYERS 6
*/

/*
typedef ap_fixed<16,8> fp1;
typedef ap_fixed<16,8> fp2;
typedef ap_fixed<16,8> fp3;
*/

typedef float fp1;
typedef float fp2;
typedef float fp3;

typedef ap_uint<1> int1;

//void TNN(int1* finaldone, int seq_out, int nheads_out, int nlayers_out, int embed_out, int hidden_out, int outdim_out, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 weight_stream1[12*NUM_ENCODER_LAYERS*EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream2[EMBEDDING_DIM*OUTPUT_DIM], fp3 out_stream[SEQ_LEN*OUTPUT_DIM]);
//void TNN(int *batch, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)], fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*OUTPUT_DIM], fp3 out_stream[SEQ_LEN*OUTPUT_DIM]);
void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS]);

/*
extern void feedforward1(fp1 (*in)[EMBEDDING_DIM/NUM_HEADS], fp3 (*out)[EMBEDDING_DIM], fp2 (*w1)[EMBEDDING_DIM/NUM_HEADS], int *index, int s, int n, int k);
extern void feedforward2(fp1 (*in)[EMBEDDING_DIM/NUM_HEADS], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[EMBEDDING_DIM/NUM_HEADS], int *index, int s, int n, int k);
extern void feedforward_last(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[NUM_LABELS], fp2 (*w1)[EMBEDDING_DIM], fp2* b1, int n, int k, int s);

//void self_attention(fp1* x, fp2* wq, fp2* wk, fp2* wv,  fp2* bq, fp2* bk, fp2* bv, fp3* vs, int n, int d, int t, int factor);
extern void self_attention(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], int n, int d, int t, int factor);

extern void biasAdd(fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], fp2 *bq, fp2 *bk, fp2 *bv, int n, int d, int t);
extern void biasAdd2(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d);
extern void biasAdd3(fp3 (*qq)[HIDDEN_DIM], fp2 *bq, int n, int d);
extern void biasAdd4(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d);

extern void attention_score(fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], fp2 (*vs)[EMBEDDING_DIM], int *seq, int *emb, int n, int d, int t, int factor);
//extern void pooler(fp1 (*h)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2 (*w2)[EMBEDDING_DIM], fp2 *b2, int seq, int embed);

extern void loadIn(fp1 *x1, fp1 *in_stream, int *index, int seq_out);
extern void loadIn2(fp2 (*x1)[EMBEDDING_DIM/NUM_HEADS], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out);
extern void loadIn3(fp3 (*x1)[EMBEDDING_DIM/NUM_HEADS], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out);

extern void loadWq1(fp2 *wq1_1, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq2(fp2 *wq1_2, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq3(fp2 *wq1_3, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq4(fp2 *wq1_4, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq5(fp2 *wq1_5, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq6(fp2 *wq1_6, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq7(fp2 *wq1_7, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq8(fp2 *wq1_8, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq9(fp2 *wq1_9, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq10(fp2 *wq1_10, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq11(fp2 *wq1_11, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);
extern void loadWq12(fp2 *wq1_12, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor);

extern void loadWo(fp2 (*wo1)[EMBEDDING_DIM/NUM_HEADS], fp2 *weight_stream1, int *index, int embed_out, int nheads_out);
extern void loadWn(fp2 *gamma1, fp2 *weight_stream1, int *index, int embed_out);
//extern void loadW1(fp2 (*w1)[EMBEDDING_DIM], fp2 *weight_stream1, int *index, int embed_out);
//extern void loadW2(fp2 (*w2)[HIDDEN_DIM], fp2 *weight_stream1, int *index, int embed_out);

extern void loadBq1(fp2 *bq1,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq2(fp2 *bq2,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq3(fp2 *bq3,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq4(fp2 *bq4,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq5(fp2 *bq5,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq6(fp2 *bq6,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq7(fp2 *bq7,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq8(fp2 *bq8,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq9(fp2 *bq9,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq10(fp2 *bq10,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq11(fp2 *bq11,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);
extern void loadBq12(fp2 *bq12,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor);

extern void loadBiasAll(fp2 *beta2, fp2 *bias_stream, int *index2, int embed_out);
extern void loadBiasInter(fp2 *beta2, fp2 *bias_stream, int *index2, int hidden_out);
extern void addNorm1(fp3 (*ff_out1)[EMBEDDING_DIM], fp1 *x1, int seq_out, int embed_out);
extern void addNorm2(fp3 (*ff_out2)[EMBEDDING_DIM], fp1 (*LN_out1)[EMBEDDING_DIM], int seq_out, int embed_out);

extern void layerNorm(fp1 (*x)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2* gamma, fp2* beta, fp1 *eps, int seq, int embed);
extern fp3 relu(fp1 x);
extern fp3 gelu(fp1 x);
extern void softmax(fp1 (*x)[EMBEDDING_DIM/NUM_HEADS], int n, int d, int t);

template<class T, class U>
extern T sig(U x);

template<class T, class U>
extern T tan(U x);


extern fp1 encoder_output[SEQ_LEN][EMBEDDING_DIM];
extern fp2 class_output[NUM_LABELS];
extern fp1 inStream[SEQ_LEN*EMBEDDING_DIM];
extern fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)];
extern fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM];
extern fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM];
extern fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)];
extern fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM];
extern fp3 out_stream[SEQ_LEN*NUM_LABELS];
*/
extern fp2  wq1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

/*
extern fp2  wq1_9[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_9[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_9[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_10[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_10[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_10[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_11[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_11[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_11[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];

extern fp2  wq1_12[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wk1_12[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
extern fp2  wv1_12[8*EMBEDDING_DIM/(NUM_HEADS)];//*EMBEDDING_DIM];
*/
extern fp2  bq1[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk1[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv1[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq2[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk2[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv2[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq3[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk3[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv3[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq4[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk4[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv4[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq5[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk5[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv5[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq6[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk6[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv6[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq7[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk7[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv7[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq8[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk8[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv8[(EMBEDDING_DIM/NUM_HEADS)];
/*
extern fp2  bq9[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk9[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv9[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq10[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk10[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv10[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq11[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk11[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv11[(EMBEDDING_DIM/NUM_HEADS)];

extern fp2  bq12[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bk12[(EMBEDDING_DIM/NUM_HEADS)];
extern fp2  bv12[(EMBEDDING_DIM/NUM_HEADS)];
*/
extern int SEQ;
extern int BATCH;
extern int EMBEDDING;
extern int HEADS;
extern int HIDDEN_D;
extern int OUTPUT_D;
extern int ENCODER_LAYERS;
extern int LABEL;


extern fp1 encoder_output[SEQ_LEN][EMBEDDING_DIM];
extern fp2 class_output[NUM_LABELS];
extern fp1 inStream[SEQ_LEN*EMBEDDING_DIM];
extern fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)];
extern fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM];
extern fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM];
extern fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)];
extern fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM];
extern fp3 out_stream[SEQ_LEN*NUM_LABELS];

//extern fp2 bias_stream4[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)];
//extern fp2 weight_stream4[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)];

//#endif
