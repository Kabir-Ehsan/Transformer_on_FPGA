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

	  fp1 inStream[SEQ_LEN*EMBEDDING_DIM] = {0};
	  fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)]  = {0};
	  fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM] = {0};
	  fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM] = {0};
	  fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)] = {0};
	  fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM] = {0};
	  fp3 out_stream[SEQ_LEN*NUM_LABELS] = {0};



		 int w_index1 = 0;
		 int w_index2 = 0;
		 int w_index3 = 0;
		 int w_index4 = 0;
		 int w_index5 = 0;
		 int w_index6 = 0;
		 int w_index7 = 0;
		 int w_index8 = 0;
		 int w_index9 = 0;

		 int b_index1 = 0;
		 int b_index2 = 0;
		 int b_index3 = 0;
		 int b_index4 = 0;
		 int b_index5 = 0;
		 int b_index6 = 0;
		 int b_index7 = 0;
		 int b_index8 = 0;
		 int b_index9 = 0;


		 int SEQ = 64;//128;//256;//512;//16;//32;//;32;//
		 int BATCH = 1;
		 int EMBEDDING = 768;//512;256;//128;//320;//
		 int HEADS = 8;//6;//4;
		 int HIDDEN_D = 4*EMBEDDING;
		 int OUTPUT_D = EMBEDDING;//128;//768;
		 int ENCODER_LAYERS = 1;
		 int LABEL = 2;



