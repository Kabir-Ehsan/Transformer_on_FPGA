//#ifdef TNN_HEADER
//#define TNN_HEADER

#include"stdio.h"
#include"stdlib.h"
#include "math.h"



#include "hls_math.h"
#include "ap_fixed.h"
#include "hls_stream.h"
#include "ap_axi_sdata.h"
#include "assert.h"
#include "ap_int.h"


// Define the input and output sizes


#define BATCH_SIZE 1//8//32
#define SEQ_LEN 64//128//256//512//16//32//64//32//2//
#define EMBEDDING_DIM 768//512//256//320//128//768//4//8
#define NUM_HEADS 8//6//4//12//3//2//16//
#define HIDDEN_DIM 4*EMBEDDING_DIM //2048
#define OUTPUT_DIM EMBEDDING_DIM//128//768//530//16//1000
#define TILE_SIZE 64//128//4//1//EMBEDDING_DIM

#define TILE_SCORE1 1//EMBEDDING_DIM
#define TILE_SCORE2 6//EMBEDDING_DIM

#define NUM_ENCODER_LAYERS 1//12//8//24 //6
#define NUM_DECODER_LAYERS 1//6
#define NUM_LABELS 2
//#define epsilon 1*e-12

#define fact1 EMBEDDING_DIM/NUM_HEADS
#define fact2 (EMBEDDING_DIM)/(fact1)
#define fact3 (HIDDEN_DIM)/(fact1)
#define fact4 fact1/TILE_SCORE1
#define fact5 EMBEDDING_DIM/TILE_SCORE2
#define fact6 HIDDEN_DIM/TILE_SCORE1
#define wfact (TILE_SIZE*EMBEDDING_DIM)/(NUM_HEADS)

/*
typedef ap_fixed<16,8> fp1;
typedef ap_fixed<16,8> fp2;
typedef ap_fixed<16,8> fp3;
*/

typedef ap_fixed<8,4> fp1;
typedef ap_fixed<8,4> fp2;
typedef ap_fixed<8,4> fp3;

/*
typedef float fp1;
typedef float fp2;
typedef float fp3;
*/

typedef ap_uint<1> int1;

//void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS]);
//void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, int *tile_score1, int *tile_score2, int *over, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*EMBEDDING_DIM]);
/*
void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, int *over, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(4*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_streamQ1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)],
		fp2 bias_streamQ1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ4[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamK1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK4[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamV1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV4[NUM_ENCODER_LAYERS*(fact1)],
		fp2 weight_stream1[NUM_ENCODER_LAYERS*(9*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS], int *tile_score1, int *tile_score2);
*/

void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, int *over, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(4*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_streamQ1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)],
		fp2 weight_streamQ5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)],
		fp2 bias_streamQ1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ4[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamK1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK4[NUM_ENCODER_LAYERS*(fact1)],	fp2 bias_streamK5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamV1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV4[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 weight_stream1[NUM_ENCODER_LAYERS*(9*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS], int *tile_score1, int *tile_score2);


extern fp2  wq1_1[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_1[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_1[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_2[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_2[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_2[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_3[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_3[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_3[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_4[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_4[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_4[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_5[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_5[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_5[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_6[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_6[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_6[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_7[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_7[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_7[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_8[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_8[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_8[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_9[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_9[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_9[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_10[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_10[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_10[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_11[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_11[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_11[wfact];//*EMBEDDING_DIM];

extern fp2  wq1_12[wfact];//*EMBEDDING_DIM];
extern fp2  wk1_12[wfact];//*EMBEDDING_DIM];
extern fp2  wv1_12[wfact];//*EMBEDDING_DIM];


extern fp2  bq1[fact1];
extern fp2  bk1[fact1];
extern fp2  bv1[fact1];

extern fp2  bq2[fact1];
extern fp2  bk2[fact1];
extern fp2  bv2[fact1];

extern fp2  bq3[fact1];
extern fp2  bk3[fact1];
extern fp2  bv3[fact1];

extern fp2  bq4[fact1];
extern fp2  bk4[fact1];
extern fp2  bv4[fact1];

extern fp2  bq5[fact1];
extern fp2  bk5[fact1];
extern fp2  bv5[fact1];

extern fp2  bq6[fact1];
extern fp2  bk6[fact1];
extern fp2  bv6[fact1];

extern fp2  bq7[fact1];
extern fp2  bk7[fact1];
extern fp2  bv7[fact1];

extern fp2  bq8[fact1];
extern fp2  bk8[fact1];
extern fp2  bv8[fact1];

extern fp2  bq9[fact1];
extern fp2  bk9[fact1];
extern fp2  bv9[fact1];

extern fp2  bq10[fact1];
extern fp2  bk10[fact1];
extern fp2  bv10[fact1];

extern fp2  bq11[fact1];
extern fp2  bk11[fact1];
extern fp2  bv11[fact1];

extern fp2  bq12[fact1];
extern fp2  bk12[fact1];
extern fp2  bv12[fact1];

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



