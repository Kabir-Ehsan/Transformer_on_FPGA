/*
#define BATCH_SIZE 1//8//32
#define SEQ_LEN 16//64//2//128
#define EMBEDDING_DIM 128//768//4//8//512
#define NUM_HEADS 8//12//2//16//
#define HIDDEN_DIM 4*EMBEDDING_DIM //2048
#define OUTPUT_DIM 128//768//530//16//1000

#define NUM_ENCODER_LAYERS 1//12//24 //6
#define NUM_DECODER_LAYERS 1//6
#define NUM_LABELS 2

typedef float fp1;
typedef float fp2;
typedef float fp3;
*/
#include "TNN_5_2.h"

extern float inputs[SEQ_LEN][EMBEDDING_DIM];

extern float query0[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias0[EMBEDDING_DIM];
extern float key0[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias0[EMBEDDING_DIM];
extern float value0[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias0[EMBEDDING_DIM];
extern float encode_intermediate_weight0[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias0[HIDDEN_DIM];
extern float encode_out_weight0[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias0[EMBEDDING_DIM];
extern float encode_LN_weight0[EMBEDDING_DIM];
extern float encode_LN_weight0[EMBEDDING_DIM];
extern float encode_LN_bias0[EMBEDDING_DIM];
extern float attention_weight0[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias0[EMBEDDING_DIM];
extern float attention_LN_weight0[EMBEDDING_DIM];
extern float attention_LN_bias0[EMBEDDING_DIM];

extern float query1[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias1[EMBEDDING_DIM];
extern float key1[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias1[EMBEDDING_DIM];
extern float value1[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias1[EMBEDDING_DIM];
extern float encode_intermediate_weight1[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias1[HIDDEN_DIM];
extern float encode_out_weight1[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias1[EMBEDDING_DIM];
extern float encode_LN_weight1[EMBEDDING_DIM];
extern float encode_LN_weight1[EMBEDDING_DIM];
extern float encode_LN_bias1[EMBEDDING_DIM];
extern float attention_weight1[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias1[EMBEDDING_DIM];
extern float attention_LN_weight1[EMBEDDING_DIM];
extern float attention_LN_bias1[EMBEDDING_DIM];


extern float query2[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias2[EMBEDDING_DIM];
extern float key2[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias2[EMBEDDING_DIM];
extern float value2[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias2[EMBEDDING_DIM];
extern float encode_intermediate_weight2[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias2[HIDDEN_DIM];
extern float encode_out_weight2[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias2[EMBEDDING_DIM];
extern float encode_LN_weight2[EMBEDDING_DIM];
extern float encode_LN_weight2[EMBEDDING_DIM];
extern float encode_LN_bias2[EMBEDDING_DIM];
extern float attention_weight2[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias2[EMBEDDING_DIM];
extern float attention_LN_weight2[EMBEDDING_DIM];
extern float attention_LN_bias2[EMBEDDING_DIM];

extern float query3[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias3[EMBEDDING_DIM];
extern float key3[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias3[EMBEDDING_DIM];
extern float value3[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias3[EMBEDDING_DIM];
extern float encode_intermediate_weight3[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias3[HIDDEN_DIM];
extern float encode_out_weight3[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias3[EMBEDDING_DIM];
extern float encode_LN_weight3[EMBEDDING_DIM];
extern float encode_LN_weight3[EMBEDDING_DIM];
extern float encode_LN_bias3[EMBEDDING_DIM];
extern float attention_weight3[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias3[EMBEDDING_DIM];
extern float attention_LN_weight3[EMBEDDING_DIM];
extern float attention_LN_bias3[EMBEDDING_DIM];

extern float query4[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias4[EMBEDDING_DIM];
extern float key4[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias4[EMBEDDING_DIM];
extern float value4[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias4[EMBEDDING_DIM];
extern float encode_intermediate_weight4[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias4[HIDDEN_DIM];
extern float encode_out_weight4[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias4[EMBEDDING_DIM];
extern float encode_LN_weight4[EMBEDDING_DIM];
extern float encode_LN_weight4[EMBEDDING_DIM];
extern float encode_LN_bias4[EMBEDDING_DIM];
extern float attention_weight4[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias4[EMBEDDING_DIM];
extern float attention_LN_weight4[EMBEDDING_DIM];
extern float attention_LN_bias4[EMBEDDING_DIM];


extern float query5[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias5[EMBEDDING_DIM];
extern float key5[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias5[EMBEDDING_DIM];
extern float value5[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias5[EMBEDDING_DIM];
extern float encode_intermediate_weight5[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias5[HIDDEN_DIM];
extern float encode_out_weight5[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias5[EMBEDDING_DIM];
extern float encode_LN_weight5[EMBEDDING_DIM];
extern float encode_LN_weight5[EMBEDDING_DIM];
extern float encode_LN_bias5[EMBEDDING_DIM];
extern float attention_weight5[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias5[EMBEDDING_DIM];
extern float attention_LN_weight5[EMBEDDING_DIM];
extern float attention_LN_bias5[EMBEDDING_DIM];

extern float query6[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias6[EMBEDDING_DIM];
extern float key6[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias6[EMBEDDING_DIM];
extern float value6[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias6[EMBEDDING_DIM];
extern float encode_intermediate_weight6[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias6[HIDDEN_DIM];
extern float encode_out_weight6[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias6[EMBEDDING_DIM];
extern float encode_LN_weight6[EMBEDDING_DIM];
extern float encode_LN_weight6[EMBEDDING_DIM];
extern float encode_LN_bias6[EMBEDDING_DIM];
extern float attention_weight6[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias6[EMBEDDING_DIM];
extern float attention_LN_weight6[EMBEDDING_DIM];
extern float attention_LN_bias6[EMBEDDING_DIM];


extern float query7[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias7[EMBEDDING_DIM];
extern float key7[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias7[EMBEDDING_DIM];
extern float value7[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias7[EMBEDDING_DIM];
extern float encode_intermediate_weight7[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias7[HIDDEN_DIM];
extern float encode_out_weight7[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias7[EMBEDDING_DIM];
extern float encode_LN_weight7[EMBEDDING_DIM];
extern float encode_LN_weight7[EMBEDDING_DIM];
extern float encode_LN_bias7[EMBEDDING_DIM];
extern float attention_weight7[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias7[EMBEDDING_DIM];
extern float attention_LN_weight7[EMBEDDING_DIM];
extern float attention_LN_bias7[EMBEDDING_DIM];

extern float query8[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias8[EMBEDDING_DIM];
extern float key8[EMBEDDING_DIM][EMBEDDING_DIM];
extern float key_bias8[EMBEDDING_DIM];
extern float value8[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias8[EMBEDDING_DIM];
extern float encode_intermediate_weight8[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias8[HIDDEN_DIM];
extern float encode_out_weight8[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias8[EMBEDDING_DIM];
extern float encode_LN_weight8[EMBEDDING_DIM];
extern float encode_LN_weight8[EMBEDDING_DIM];
extern float encode_LN_bias8[EMBEDDING_DIM];
extern float attention_weight8[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias8[EMBEDDING_DIM];
extern float attention_LN_weight8[EMBEDDING_DIM];
extern float attention_LN_bias8[EMBEDDING_DIM];


extern float query9[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias9[EMBEDDING_DIM];
extern float key9[768][EMBEDDING_DIM];
extern float key_bias9[EMBEDDING_DIM];
extern float value9[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias9[EMBEDDING_DIM];
extern float encode_intermediate_weight9[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias9[HIDDEN_DIM];
extern float encode_out_weight9[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias9[EMBEDDING_DIM];
extern float encode_LN_weight9[EMBEDDING_DIM];
extern float encode_LN_weight9[EMBEDDING_DIM];
extern float encode_LN_bias9[EMBEDDING_DIM];
extern float attention_weight9[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias9[EMBEDDING_DIM];
extern float attention_LN_weight9[EMBEDDING_DIM];
extern float attention_LN_bias9[EMBEDDING_DIM];


extern float query10[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias10[EMBEDDING_DIM];
extern float key10[768][EMBEDDING_DIM];
extern float key_bias10[EMBEDDING_DIM];
extern float value10[768][EMBEDDING_DIM];
extern float value_bias10[EMBEDDING_DIM];
extern float encode_intermediate_weight10[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias10[HIDDEN_DIM];
extern float encode_out_weight10[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias10[EMBEDDING_DIM];
extern float encode_LN_weight10[EMBEDDING_DIM];
extern float encode_LN_weight10[EMBEDDING_DIM];
extern float encode_LN_bias10[EMBEDDING_DIM];
extern float attention_weight10[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias10[EMBEDDING_DIM];
extern float attention_LN_weight10[EMBEDDING_DIM];
extern float attention_LN_bias10[EMBEDDING_DIM];


extern float query11[EMBEDDING_DIM][EMBEDDING_DIM];
extern float query_bias11[EMBEDDING_DIM];
extern float key11[768][EMBEDDING_DIM];
extern float key_bias11[EMBEDDING_DIM];
extern float value11[EMBEDDING_DIM][EMBEDDING_DIM];
extern float value_bias11[EMBEDDING_DIM];
extern float encode_intermediate_weight11[HIDDEN_DIM][EMBEDDING_DIM];
extern float encode_intermediate_bias11[HIDDEN_DIM];
extern float encode_out_weight11[EMBEDDING_DIM][HIDDEN_DIM];
extern float encode_out_bias11[EMBEDDING_DIM];
extern float encode_LN_weight11[EMBEDDING_DIM];
extern float encode_LN_weight11[EMBEDDING_DIM];
extern float encode_LN_bias11[EMBEDDING_DIM];
extern float attention_weight11[EMBEDDING_DIM][EMBEDDING_DIM];
extern float attention_bias11[EMBEDDING_DIM];
extern float attention_LN_weight11[EMBEDDING_DIM];
extern float attention_LN_bias11[EMBEDDING_DIM];

extern float pool_weight[EMBEDDING_DIM][EMBEDDING_DIM];
extern float pool_bias[EMBEDDING_DIM];
extern float classify_weight[NUM_LABELS][EMBEDDING_DIM];
extern float classify_bias[NUM_LABELS];

extern int w_index1;
extern int w_index2;
extern int w_index3;
extern int w_index4;
extern int w_index5;
extern int w_index6;
extern int w_index7;
extern int w_index8;
extern int w_index9;

extern int b_index1;
extern int b_index2;
extern int b_index3;
extern int b_index4;
extern int b_index5;
extern int b_index6;
extern int b_index7;
extern int b_index8;
extern int b_index9;

extern void encoder_layer1(int SEQ1, int EMBEDDING1, int HEADS1, int HIDDEN_D1, int TILE1);
extern void encoder_layer2();
extern void encoder_layer3();
extern void encoder_layer4();
extern void encoder_layer5();
extern void encoder_layer6();
extern void encoder_layer7();
extern void encoder_layer8();
extern void encoder_layer9();
extern void encoder_layer10();
extern void encoder_layer11();
extern void encoder_layer12();

//#endif
