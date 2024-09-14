#include "TNN_5.h"
#include "addNorm2.h"
#include "addNorm.h"
#include "loadBiasInter.h"
#include "loadBiasAll.h"
#include "loadBq.h"
#include "loadWq.h"
#include "loadWn.h"
#include "loadIn.h"
#include "softmax.h"
#include "activation.h"
#include "layerNorm.h"
#include "score.h"
#include "loadWo.h"
#include "biasAdd.h"
#include "self_attention.h"
#include "feedforward1.h"
#include "feedforward2.h"
#include "feedforward_last.h"

#include <iostream>

using namespace std;
//void TNN(int1* finaldone, int seq_out, int nheads_out, int nlayers_out, int embed_out, int hidden_out, int outdim_out, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 weight_stream1[12*NUM_ENCODER_LAYERS*EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream2[EMBEDDING_DIM*OUTPUT_DIM], fp3 out_stream[SEQ_LEN*OUTPUT_DIM])
void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_stream1[NUM_ENCODER_LAYERS*(12*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS])
{
	//int1 tempDone[1];
	int enc_size1 = 0;
	int i=0,k=0,l=0,m=0, index=0, index2=0, index3 = 0, index4=0, index5=0, index6=0, s=0, e=0;
	int j=0;
	int ii=0;

	fp1 eps = 1e-12;

	fp1 qq1[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk1[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv1[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq2[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk2[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv2[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq3[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk3[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv3[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq4[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk4[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv4[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq5[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk5[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv5[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq6[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk6[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv6[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq7[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk7[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv7[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq8[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk8[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv8[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
/*
	fp1 qq9[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk9[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv9[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq10[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk10[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv10[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq11[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk11[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv11[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};

	fp1 qq12[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 kk12[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
	fp1 vv12[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS] = {0};
*/
	//EMBEDDING_DIM/NUM_HEADS];

	  static fp2  wq1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_1[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_2[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_3[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_4[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_5[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_6[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_7[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  static fp2  wq1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wk1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  static fp2  wv1_8[TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

/*
	  fp2  wq1_9[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_9[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_9[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_10[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_10[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_10[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_11[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_11[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_11[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_12[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_12[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_12[8*EMBEDDING_DIM/(NUM_HEADS)] = {0};//*EMBEDDING_DIM];
*/
	  fp2  bq1[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk1[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv1[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq2[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk2[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv2[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq3[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk3[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv3[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq4[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk4[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv4[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq5[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk5[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv5[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq6[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk6[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv6[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq7[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk7[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv7[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq8[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk8[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv8[(EMBEDDING_DIM/NUM_HEADS)] = {0};


/*
	  fp2  bq9[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk9[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv9[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq10[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk10[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv10[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq11[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk11[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv11[(EMBEDDING_DIM/NUM_HEADS)] = {0};

	  fp2  bq12[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bk12[(EMBEDDING_DIM/NUM_HEADS)] = {0};
	  fp2  bv12[(EMBEDDING_DIM/NUM_HEADS)] = {0};
*/
	  fp2  gamma1[EMBEDDING_DIM];
	  fp2  beta1[EMBEDDING_DIM];

//	  fp2  gamma2[EMBEDDING_DIM];
//	  fp2  beta2[EMBEDDING_DIM];

	  static fp2  wo1[EMBEDDING_DIM/NUM_HEADS][EMBEDDING_DIM/NUM_HEADS];

//	  static fp2  w1[EMBEDDING_DIM/NUM_HEADS][EMBEDDING_DIM/NUM_HEADS];//[4*EMBEDDING_DIM][EMBEDDING_DIM];
//	  static fp2  w2[EMBEDDING_DIM/NUM_HEADS][EMBEDDING_DIM/NUM_HEADS];//[EMBEDDING_DIM][4*EMBEDDING_DIM];

//	  static fp2  wp[EMBEDDING_DIM][EMBEDDING_DIM];

	  static fp2 weight_class[NUM_LABELS][EMBEDDING_DIM];

	  static fp1  x1[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
/*	  static fp1  x2[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x3[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x4[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x5[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x6[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x7[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  static fp1  x8[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
*/

	  static fp3  ff_out1[SEQ_LEN][EMBEDDING_DIM]; //[BATCH_SIZE
	  static fp3  ff_out1_temp[SEQ_LEN][EMBEDDING_DIM/(NUM_HEADS)];
      static fp3  ff_out2[SEQ_LEN][HIDDEN_DIM]; //[BATCH_SIZE

      static fp3  pool_out[SEQ_LEN][EMBEDDING_DIM];
      static fp3  LN_out1[SEQ_LEN][EMBEDDING_DIM]; //[BATCH_SIZE

      static fp2  bff_1[EMBEDDING_DIM] = {0};
      static fp2  bff_2[HIDDEN_DIM] = {0};
      static fp2  bff_3[EMBEDDING_DIM] = {0};

      static fp2  bp[EMBEDDING_DIM] = {0};
      static fp2  bclass[NUM_LABELS] = {0};

      static fp2  bout[SEQ_LEN*OUTPUT_DIM] = {0};

      fp2 vs[SEQ_LEN][EMBEDDING_DIM];

      static fp2 vs_temp[SEQ_LEN][EMBEDDING_DIM/(NUM_HEADS)];

      static fp3 out_temp[SEQ_LEN][NUM_LABELS];


	weightClass1:for(i=0;i<NUM_LABELS;i++)
 	{
 		if(i<(*labels))
 		{
 			weightClass2:for(j=0;j<EMBEDDING_DIM;j++)
 		 	{
 				if(j<(*embed_out))
 				{
 					weight_class[i][j] = weight_stream3[i*(*embed_out)+j];
 					//cout<<"weight_class["<< i << ',' << j <<"]=  " << weight_class[i][j]<< "\n";
 				}
 				else
 					break;
 		 	}
 			//cout<<"weight_out["<<i<<"]=  " << weight_out[i]<< "\n";
 		}
 		else
 			break;

 	}

 	bias_pool:for(i=0;i<EMBEDDING_DIM;i++)
 	{
 		if(i<(*embed_out))
 		{
 		 	bp[i] = bias_stream2[i];
 		}
 		else
 			break;

 	}

 	bias_class:for(i=0;i<OUTPUT_DIM;i++)
 	{
 		if(i<(*labels))
 		{
 		 	bclass[i] = bias_stream2[i+(*embed_out)];
 		}
 		else
 			break;

 	}





//index = 0;
layers:for(l=0; l<NUM_ENCODER_LAYERS; l++) //
{
	cout << "layer:" << l << "\n";
	if(l<(*nlayers_out))
	{
		k = 0;
		s = 0;
		e = 0;
		index3=0;
		index4=0;
		index5=0;


	//	cout<< "self attention 1 start" << '\n';

				//self_attention(x1, wq1_1[j], wk1_1[j], wv1_1[j], bq[j], bk[j], bv[j], vs1[j], *seq_out, *embed_out, *nheads_out);//SEQ_LEN, EMBEDDING_DIM, NUM_HEADS);//sq, em, ho);//

				Tiles:for(j=0;j<EMBEDDING_DIM/TILE_SIZE;j++)
				{
					//cout << "Tile: " << j << "\n";
					if(j<((*embed_out)/(*tile)))
					{
						loadIn(x1, in_stream, &index3, *seq_out, *tile); //x2, x3, x4, x5, x6, x7, x8,
						loadWq1(wq1_1, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq2(wq1_2, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq3(wq1_3, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq4(wq1_4, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq5(wq1_5, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq6(wq1_6, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq7(wq1_7, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq8(wq1_8, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						/*						loadWq9(wq1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq10(wq1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq11(wq1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq12(wq1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
*/
						loadWq1(wk1_1, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq2(wk1_2, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq3(wk1_3, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq4(wk1_4, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq5(wk1_5, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq6(wk1_6, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq7(wk1_7, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq8(wk1_8, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						/*						loadWq9(wk1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq10(wk1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq11(wk1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq12(wk1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
*/
						loadWq1(wv1_1, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq2(wv1_2, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq3(wv1_3, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq4(wv1_4, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq5(wv1_5, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq6(wv1_6, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq7(wv1_7, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						loadWq8(wv1_8, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, 1);
						/*						loadWq9(wv1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq10(wv1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq11(wv1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
						loadWq12(wv1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), 1);
*/

						self_attention(x1, wq1_1, wk1_1, wv1_1, qq1, kk1, vv1, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_2, wk1_2, wv1_2, qq2, kk2, vv2, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_3, wk1_3, wv1_3, qq3, kk3, vv3, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_4, wk1_4, wv1_4, qq4, kk4, vv4, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_5, wk1_5, wv1_5, qq5, kk5, vv5, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_6, wk1_6, wv1_6, qq6, kk6, vv6, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_7, wk1_7, wv1_7, qq7, kk7, vv7, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						self_attention(x1, wq1_8, wk1_8, wv1_8, qq8, kk8, vv8, *seq_out, ((*embed_out)), *nheads_out, (*tile), 1);
						/*						self_attention(x1, wq1_9, wk1_9, wv1_9, qq9, kk9, vv9, *seq_out, ((*embed_out)), *nheads_out, 1);
						self_attention(x1, wq1_10, wk1_10, wv1_10, qq10, kk10, vv10, *seq_out, ((*embed_out)), *nheads_out, 1);
						self_attention(x1, wq1_11, wk1_11, wv1_11, qq11, kk11, vv11, *seq_out, ((*embed_out)), *nheads_out, 1);
						self_attention(x1, wq1_12, wk1_12, wv1_12, qq12, kk12, vv12, *seq_out, ((*embed_out)), *nheads_out, 1);
*/
					}
					else
						break;
				}

				loadBq1(bq1, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq2(bq2, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq3(bq3, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq4(bq4, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq5(bq5, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq6(bq6, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq7(bq7, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq8(bq8, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
/*				loadBq9(bq9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq10(bq10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq11(bq11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq12(bq12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
*/
				loadBq1(bk1, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq2(bk2, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq3(bk3, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq4(bk4, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq5(bk5, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq6(bk6, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq7(bk7, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq8(bk8, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				/*				loadBq9(bk9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq10(bk10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq11(bk11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq12(bk12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
*/
				loadBq1(bv1, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq2(bv2, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq3(bv3, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq4(bv4, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq5(bv5, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq6(bv6, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq7(bv7, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq8(bv8, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				/*				loadBq9(bv9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq10(bv10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq11(bv11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
				loadBq12(bv12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), 1);
*/
				biasAdd(qq1, kk1, vv1, bq1, bk1, bv1, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq2, kk2, vv2, bq2, bk2, bv2, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq3, kk3, vv3, bq3, bk3, bv3, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq4, kk4, vv4, bq4, bk4, bv4, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq5, kk5, vv5, bq5, bk5, bv5, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq6, kk6, vv6, bq6, bk6, bv6, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq7, kk7, vv7, bq7, bk7, bv7, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq8, kk8, vv8, bq8, bk8, bv8, *seq_out, ((*embed_out)), *nheads_out);
				/*				biasAdd(qq9, kk9, vv9, bq9, bk9, bv9, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq10, kk10, vv10, bq10, bk10, bv10, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq11, kk11, vv11, bq11, bk11, bv11, *seq_out, ((*embed_out)), *nheads_out);
				biasAdd(qq12, kk12, vv12, bq12, bk12, bv12, *seq_out, ((*embed_out)), *nheads_out);
*/
				attention_score(qq1,  kk1, vv1, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq2,  kk2, vv2, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq3,  kk3, vv3, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq4,  kk4, vv4, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq5,  kk5, vv5, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq6,  kk6, vv6, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq7,  kk7, vv7, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq8,  kk8, vv8, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				/*				attention_score(qq9,  kk9, vv9, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq10,  kk10, vv10, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq11,  kk11, vv11, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
				attention_score(qq12,  kk12, vv12, vs, &s, &e, *seq_out, (*embed_out), *nheads_out, 1);
*/


/*
				tile1:for(i=0;i<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);i++)
				{
					if(i<((*embed_out)/((*embed_out)/(*nheads_out))))
					{
						index5 = i;
						index4 = i;
						tile2:for(j=0;j<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);j++)
						{
							if(j<((*embed_out)/((*embed_out)/(*nheads_out))))
							{
								loadIn2(vs_temp, vs, &index4, *seq_out, *embed_out, *nheads_out);
								loadWo(wo1, weight_stream1, &index, *embed_out, *nheads_out);
								feedforward1(vs_temp, ff_out1, wo1, &index5, *seq_out, (*embed_out)/(*nheads_out), (*embed_out)/(*nheads_out));// new for tiling
							}
							else
								break;

						}
					}
					else
						break;
				}


				loadBiasAll(bff_1, bias_stream, &index2, *embed_out);
				biasAdd2(ff_out1, bff_1, *seq_out, *embed_out);

				loadWn(gamma1, weight_stream1, &index, *embed_out);
				loadBiasAll(beta1, bias_stream, &index2, *embed_out);

				addNorm1(ff_out1, x1, *seq_out, *embed_out);

				layerNorm(ff_out1, LN_out1, gamma1, beta1, &eps, *seq_out, *embed_out);

				index4 = 0;
				index5 = 0;
				tile3:for(i=0;i<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);i++)
				{
					if(i<((*embed_out)/((*embed_out)/(*nheads_out))))
					{
						index5 = i;
						index4 = i;
						tile4:for(j=0;j<HIDDEN_DIM/(EMBEDDING_DIM/NUM_HEADS);j++)
						{
							if(j<((*embed_out)/((*embed_out)/(*nheads_out))))
							{
								loadIn2(ff_out1_temp, LN_out1, &index4, *seq_out, *embed_out, *nheads_out); //ff_out1 chilo
								loadWo(wo1, weight_stream1, &index, *embed_out, *nheads_out); //w1
								feedforward2(ff_out1_temp, ff_out2, wo1, &index5, *seq_out, (*embed_out)/(*nheads_out), (*embed_out)/(*nheads_out));// new for tiling
							}
							else
								break;
						}
					}
					else
						break;
				}

				loadBiasInter(bff_2, bias_stream, &index2, *hidden_out);
				biasAdd3(ff_out2, bff_2, *seq_out, *hidden_out);

				reset1:for(i=0;i<SEQ_LEN;i++)
				{
					if(i<(*seq_out))
					{
						reset2:for(j=0;j<EMBEDDING_DIM;j++)
						{
							if(j<(*embed_out))
							{
								ff_out1[i][j] = 0;
								//cout<< "ff_out1 [" << i << "][" << j << "] : " << ff_out1[i][j] << "\n" ;
							}
							else
								break;

						}
					}
					else
						break;
				}

				index4 = 0;
				index5 = 0;
				tile5:for(i=0;i<HIDDEN_DIM/(EMBEDDING_DIM/NUM_HEADS);i++)
				{
					if(i<((*embed_out)/((*embed_out)/(*nheads_out))))
					{
						index5 = i;
						index4 = i;
						tile6:for(j=0;j<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);j++)
						{
							if(j<((*embed_out)/((*embed_out)/(*nheads_out))))
							{
								loadIn3(ff_out1_temp, ff_out2, &index4, *seq_out, *embed_out, *nheads_out); //ff_out3_temp
								loadWo(wo1, weight_stream1, &index, *embed_out, *nheads_out); //w2 chilo
								feedforward1(ff_out1_temp, ff_out1, wo1, &index5, *seq_out, (*embed_out)/(*nheads_out), (*embed_out)/(*nheads_out));// new for tiling
							}
							else
								break;
						}
					}
					else
						break;
				}

				loadBiasAll(bff_3, bias_stream, &index2, *embed_out);
				biasAdd2(ff_out1, bff_3, *seq_out, *embed_out); //ff_out1 chilo

		//		for(i=0;i<SEQ_LEN;i++)
		//		{
		//			for(j=0;j<EMBEDDING_DIM;j++)
		//			{
		//				cout<< "ff_out3 [" << i << "][" << j << "] : " << ff_out1[i][j] << "\n" ;
		//
		//			}
		//		}
		//

				loadWn(gamma1, weight_stream1, &index, *embed_out); //gamma2

				loadBiasAll(beta1, bias_stream, &index2, *embed_out); //beta2


				addNorm2(ff_out1, LN_out1, *seq_out, *embed_out); //ff_out1
				////layerNorm(ff_out2, LN_out2, gamma2[l], beta2[l], &eps, *seq_out, *embed_out);

				layerNorm(ff_out1, LN_out1, gamma1, beta1, &eps, *seq_out, *embed_out); //ff_out3

				inputs2_out:for(i=0;i<SEQ_LEN;i++)
				{
					if(i<(*seq_out))
					{
						inputs2_in:for(j=0;j<EMBEDDING_DIM;j++)
						{
							if(j<(*embed_out))
							{
								//x1[i*(*embed_out)+j] = LN_out2[i][j]; //EMBEDDING_DIM
								in_stream[i*(*embed_out)+j] = LN_out1[i][j]; //LN_out2 chilo
								//ff_out2[i][j] = 0;
								ff_out1[i][j] = 0;
								//pool_out[i][j] = 0;
								//cout<<"x1["<<i*EMBEDDING_DIM+j<<"]=  " << x1[i*EMBEDDING_DIM+j]<< "\n";
								//cout<< "LN_out2[" << i << "][" << j <<"]:" << LN_out2[i][j] << "\n";
							}
							else
								break;
						}
		//				cout<<"x2["<<i<<"]=  " << x2[i]<< "\n";
					}
					else
						break;

				}

				inputs3_out:for(i=0;i<SEQ_LEN;i++)
				{
					if(i<(*seq_out))
					{
						inputs3_in:for(j=0;j<HIDDEN_DIM;j++)
						{
							if(j<(*hidden_out))
							{
								ff_out2[i][j] = 0;
								//ff_out1[i][j] = 0;
								//ff_out3[i][j] = 0;
								//cout<<"x1["<<i*EMBEDDING_DIM+j<<"]=  " << x1[i*EMBEDDING_DIM+j]<< "\n";
								//cout<< "LN_out2[" << i << "][" << j <<"]:" << LN_out2[i][j] << "\n";
							}
							else
								break;
						}
		//				cout<<"x2["<<i<<"]=  " << x2[i]<< "\n";
					}
					else
						break;

				}
	*/

	}
	else
		break;

}

	//cout<< "LN_out2[" << (*seq_out)-1 << "][" << (*embed_out)-1 <<"]:" << LN_out2[(*seq_out)-1][(*embed_out)-1] << "\n";
	//cout<< "feed forward 2_2 start" << '\n';
	//feedforward2(ff_out3, ff_out4, w3, b6, w4, b7, EMBEDDING_DIM, HIDDEN_DIM);

//	cout<< "feed forward out start" << '\n';


/*
		index4 = 0;
		index5 = 0;
		tile7:for(i=0;i<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);i++)
		{
			if(i<((*embed_out)/((*embed_out)/(*nheads_out))))
			{
				index4 = i;
				index5 = i;
				tile8:for(j=0;j<EMBEDDING_DIM/(EMBEDDING_DIM/NUM_HEADS);j++)
				{
					if(j<((*embed_out)/((*embed_out)/(*nheads_out))))
					{
						loadIn2(ff_out1_temp, LN_out1, &index4, *seq_out, *embed_out, *nheads_out); //ff_out3_temp chilo
						loadWo(wo1, weight_stream2, &index6, *embed_out, *nheads_out);
						// was ff_out3_temp, w1/w2 chilo
						feedforward1(ff_out1_temp, ff_out1, wo1, &index5, *seq_out, (*embed_out)/(*nheads_out), (*embed_out)/(*nheads_out));// new for tiling
						//pooler(ff_out1_temp, pool_out, wo1, bp, *seq_out, *embed_out);
					}
					else
						break;
				}
			}
			else
				break;
		}

	biasAdd4(ff_out1, bp, *seq_out, *embed_out);

	//pooler(LN_out1, pool_out, wp, bp, *seq_out, *embed_out); // LN_out2 chilo

	feedforward_last(ff_out1, out_temp, weight_class, bclass, *embed_out, *labels, *seq_out);//EMBEDDING_DIM, OUTPUT_DIM, tempDone);//em, od, tempDone);//finaldone); //&
*/

    finalLoop1: for(i=0;i<SEQ_LEN;i++)
	{
		if(i<(*seq_out))
		{
			finalLoop2: for(j=0;j<NUM_LABELS;j++)
			{
				if(j<(*labels))
				{
					out_stream[i*(*labels)+j] = vs[i][j];//0;//out_temp[i][j];
				}
				else
					break;
			}
		}
		else
			break;
	}

	//*finaldone = tempDone[0];
	//cout<< "tempDone: " << tempDone[0] <<'\n';
	//cout<< "finaldone: " << *finaldone <<'\n';


	return;
};

/*
// new for tiling
void feedforward1(fp1 (*in)[EMBEDDING_DIM/NUM_HEADS], fp3 (*out)[EMBEDDING_DIM], fp2 (*w1)[EMBEDDING_DIM/NUM_HEADS], int *index, int s, int n, int k)
{
  //cout<< "feed forward 1 start" << '\n';
  //int m;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  col1:for (int i = 0; i<EMBEDDING_DIM/NUM_HEADS; i++) //530
		  {
			  if(i<k)
			  {
				  row1:for (int j = 0; j<EMBEDDING_DIM/NUM_HEADS; j++) //4
				  {
					  if(j<n)
					  {
						  out[l][(*index)*n+i] += in[l][j] * w1[i][j];

					  }
					  else
						  break;
				  }

			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
};

// new for tiling.
void feedforward2(fp1 (*in)[EMBEDDING_DIM/NUM_HEADS], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[EMBEDDING_DIM/NUM_HEADS], int *index, int s, int n, int k)
{
  //cout<< "feed forward 1 start" << '\n';
  //int m;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  col1:for (int i = 0; i<EMBEDDING_DIM/NUM_HEADS; i++) //530
		  {
			  if(i<k)
			  {
				  row1:for (int j = 0; j<EMBEDDING_DIM/NUM_HEADS; j++) //4
				  {
					  if(j<n)
					  {
						  out[l][(*index)*n+i] += in[l][j] * w1[i][j];
						  //cout<< "out :" << l << "," << (*index)*n+i << " : " << out[l][(*index)*n+i] << "\n" ;
					  }
					  else
						  break;
				  }

			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }

};

// Define the feedforward layer
void feedforward_last(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[NUM_LABELS], fp2 (*w1)[EMBEDDING_DIM], fp2* b1, int n, int k, int s)
{
  //cout<< "feed forward 1 start" << '\n';
  //int m;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  col1:for (int i = 0; i<NUM_LABELS; i++) //530
		  {
			  //m = 0;
			  if(i<k)
			  {
				  row1:for (int j = 0; j<EMBEDDING_DIM; j++) //4
				  {
					  if(j<n)
					  {
						  out[l][i] += in[l][j] * w1[i][j];
//						  cout<< "in[" << l << "][" << j << "] :" << in[l][j] << "\n" ;
//						  cout<< "out[" << l << "][" << i << "] :" << out[l][i] << "\n" ;
//						  cout<< "w1[" << i << "][" << j << "] :" << w1[i][j] << "\n" ;
					  }
					  else
						  break;
	//				  	  cout<< "in" << l*n+j << ":" << in[l*n+j] << "\n" ;
				  //m++;
				  }
				  out[l][i] += b1[i];
//				  cout<< "out[" << l << "][" << i << "] :" << out[l][i] << "\n" ;
			  }
			  else
				  break;
				  //cout<< "Final_OUT" << l*k+i << ":" << out[l*k+i] << "\n";
			  //out[i] = relu(out[i]);
		  }
	  }
	  else
		  break;
  }
  //softmax(out, n);

  //free(h);
};


//void self_attention(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp2* bq, fp2* bk, fp2* bv, fp3* vs, int n, int d, int t, int factor) //seq, embed, head
void self_attention(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], int n, int d, int t, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col4:for(int k = 0; k < (EMBEDDING_DIM/NUM_HEADS); k++)
			  {
				  if(k<(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row4:for (int j = 0; j < (8); j++) // EMBEDDING_DIM
					  {
						  if(j<(8))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  sq = sq + x[i*8+j] * wq[j*d/t+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  sk = sk + x[i*8+j] * wk[j*d/t+k];
							  sv = sv + x[i*8+j] * wv[j*d/t+k];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}


void biasAdd(fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], fp2 *bq, fp2 *bk, fp2 *bv, int n, int d, int t)
{
	bias_loop1:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop2:for(int k = 0; k < (EMBEDDING_DIM/NUM_HEADS); k++)
			{
				if(k<(d/(t)))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					kk[i][k] = qq[i][k]+bk[k];
					vv[i][k] = qq[i][k]+bv[k];

			//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
			//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
			//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
}

// new for tiling
void loadIn2(fp2 (*x1)[EMBEDDING_DIM/NUM_HEADS], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<EMBEDDING_DIM/NUM_HEADS; j++)
			{
				if(j<(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(embed_out/nheads_out)+j];
					//cout<<"x1["<< i <<"]["<< j <<"]=  " << x1[i][j]<< "\n";
					//cout<<"input_index: " << (*index)*(embed_out/nheads_out)+j <<"\n";
				}
				else
					break;
			}

		}
		else
			break;

	}

};

void loadIn3(fp3 (*x1)[EMBEDDING_DIM/NUM_HEADS], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<EMBEDDING_DIM/NUM_HEADS; j++)
			{
				if(j<(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(embed_out/nheads_out)+j];
					//cout<<"x1["<< i <<"]["<< j <<"]=  " << x1[i][j]<< "\n";
					//cout<<"input_index: " << (*index)*(embed_out/nheads_out)+j <<"\n";
				}
				else
					break;
			}

		}
		else
			break;

	}

};
// New for tile
void loadWo(fp2 (*wo1)[EMBEDDING_DIM/NUM_HEADS], fp2 *weight_stream1, int *index, int embed_out, int nheads_out)
{
	weightO1:for(int i=0;i<EMBEDDING_DIM/NUM_HEADS;i++)
	{
		if(i<(embed_out/nheads_out))
		{
			weightO2:for(int j=0;j<EMBEDDING_DIM/NUM_HEADS;j++)
			{
				if(j<(embed_out/nheads_out))
				{
					wo1[i][j] = weight_stream1[*index];//i*EMBEDDING_DIM+6*(*embed_out)*(*embed_out)/(*nheads_out)+l*enc_size1+j];
//					cout<<"wo1["<<i<<"]["<<j<<"]"<< wo1[i][j]<< "\n";
//					cout<<"wo_index: " << (*index) <<"\n";
					(*index)++;
				}
				else
					break;
			}

		}
		else
			break;

	}
};

void biasAdd2(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop3:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop4:for(int k = 0; k < (EMBEDDING_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};

void biasAdd3(fp3 (*qq)[HIDDEN_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop5:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop6:for(int k = 0; k < (HIDDEN_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					qq[i][k] = gelu(qq[i][k]);
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};

void biasAdd4(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop7:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop8:for(int k = 0; k < (EMBEDDING_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					qq[i][k] = tan<fp3, fp3>(qq[i][k]);
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};

void attention_score(fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], fp2 (*vs)[EMBEDDING_DIM], int *seq, int *emb, int n, int d, int t, int factor)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN];

    Score: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col5:for (int l = 0; l < SEQ_LEN; l++) //(EMBEDDING_DIM/NUM_HEADS)
				  {
					  if(l<(n)) //t*factor
					  {
						  sh = 0.0;
						  row5:for (int m = 0; m < EMBEDDING_DIM/NUM_HEADS; m++)
						  {
							  if(m<(d/(t*factor)))
							  {
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/sqrtf(EMBEDDING_DIM/NUM_HEADS);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(EMBEDDING_DIM/NUM_HEADS) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*EMBEDDING_DIM/NUM_HEADS);

  softmax(s, n, d, t);

  int sequence = *seq;
  int embedding = *emb;

  VS: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  embedding = *emb;
			  row6:for (int r = 0; r < EMBEDDING_DIM/NUM_HEADS; r++)
			  {
				  V = 0.0;
				  if(r<(d/(t*factor)))
				  {
					  col6:for (int q = 0; q < SEQ_LEN; q++)//EMBEDDING_DIM/NUM_HEADS
					  {
						  if(q<(n)) //d/(t*factor)
						  {
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[sequence][embedding] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*EMBEDDING_DIM/NUM_HEADS + q << "]:" << vs[p*EMBEDDING_DIM/NUM_HEADS + q] << "\n";

			  }
			  sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }

  	  sequence = 0;
  	  *seq = sequence;
  	  *emb = embedding;

};

void layerNorm(fp1 (*x)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2* gamma, fp2* beta, fp1 *eps, int seq, int embed)
{

	fp1 m[SEQ_LEN] = {0.0};
	fp1 v[SEQ_LEN] = {0.0};

    mean_out:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		mean_in:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				m[i] += x[i][j];
    			}
    			else
    				break;
    		}
    		m[i] /= 768;
    		//printf("m[%d] = %f\n", i, m[i]);
    	}
    	else
    		break;

    }


    variance_out:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		variance_in:for (int j = 0; j < EMBEDDING_DIM; j++)
            {
    			if(j<embed)
    			{
    				v[i] += (x[i][j]-m[i])*(x[i][j]-m[i]);
    			}
    			else
    				break;
            }
            v[i] /= 768;
            //printf("v[%d] = %f\n", i, v[i]);
    	}
    	else
    		break;
            //
    }

    norm_out1:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		norm_in1:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				out[i][j] = (x[i][j] - m[i]) / sqrt(v[i] + *eps);
 //   				printf("first_out[%d][%d]: %f \n", i, j, out[i][j]);
 //   				printf("x[%d][%d]: %f \n", i, j, x[i][j]);
    			}
    			else
    				break;
    		}
    	}
    	else
    		break;
    }

    // Normalize input using mean and variance
    norm_out2:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		norm_in2:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				out[i][j]= gamma[j] * out[i][j] + beta[j];
 //   				printf("gamma[%d]: %f \n", j, gamma[j]);
 //   				printf("beta[%d]: %f \n", j, beta[j]);
 //   				printf("second_out[%d][%d]: %f \n", i, j, out[i][j]);
    			}
    			else
    				break;
            }

    	}
    	else
    		break;
    }
};



// Define the activation function (ReLU)
fp3 relu(fp1 x)
{
  return fmaxf(0, x);
};

fp3 gelu(fp3 x)
{
    return 0.5 * x * (1.0 + erf(x / sqrt(2.0)));
};

// Define the softmax function
void softmax(fp1 (*x)[EMBEDDING_DIM/NUM_HEADS], int n, int d, int t)
{
  fp3 maxval = -INFINITY;
  fp3 sum = 0.0;
  loop1:for (int i = 0; i < (SEQ_LEN); i++)  //
  {
	  if(i<n)
	  {
		  loop1_2: for (int j = 0; j < (EMBEDDING_DIM/NUM_HEADS); j++)
		  {
			  if(j<d/t)
			  {
				  if (x[i][j] > maxval)
				  {
					  maxval = x[i][j];
				  }
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
  loop2:for (int i = 0; i < (SEQ_LEN); i++)
  {
	  if(i<n)
	  {
		  loop2_1: for (int j = 0; j < (EMBEDDING_DIM/NUM_HEADS); j++)
		  {
			  if(j<d/t)
			  {
				  	  x[i][j] = expf(x[i][j] - maxval);
				  	  sum += x[i][j];
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
  loop3:for (int i = 0; i < (SEQ_LEN); i++)
  {
	  if(i<n)
	  {
		  loop3_1: for (int j = 0; j < (EMBEDDING_DIM/NUM_HEADS); j++)
		  {
			  if(j<d/t)
			  {
				  x[i][j] /= sum;
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
};



void pooler(fp1 (*h)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2 (*w2)[EMBEDDING_DIM], fp2 *b2, int seq, int embed)
{

	 seq_pool:for(int l=0; l<SEQ_LEN; l++)
	 {
		 if(l<seq)
		 {
			 row_pool:for (int i = 0; i < EMBEDDING_DIM; i++) //4
			 {
				 if(i<embed)
				 {
					 col_pool:for (int j = 0; j < EMBEDDING_DIM; j++) //16
					 {
						 if(j<embed)
						 {
							 out[l][i] += h[l][j] * w2[i][j];
							 //cout<< "h[" << l << "][" << j << "] :" << h[l][j] << "\n" ;
							 //cout<< "out[" << l << "][" << i << "] :" << out[l][i] << "\n" ;
							 //cout<< "w2[" << i << "][" << j << "] :" << w2[i][j] << "\n" ;
						 }
						 else
							 break;
					 }

					 out[l][i] += b2[i];
					 out[l][i] = tan<fp1, fp1>(out[l][i]);
					 //printf("b2[%d]: %f\n", i, b2[i]);
				 }
				 else
					 break;
			 }
		 }
		 else
			 break;
	 }
};
*/
/*
template<class T, class U>
T sig(U x)
{
	return 1/(1+exp(-x));
};

template<class T, class U>
T tan(U x)
{
	//return (exp(-2*x)-1)/(exp(-2*x)+1);
	return (1 - 2*sig<fp1,fp1>(-2*x));
};


template<class T, class U>
T sig(U x)
{
	return U(1)/(U(1)+hls::exp(-U(1)*x));
	//fp_type(1.0)/(fp_type(1.0) + hls::exp(-fp_type(1) * sum25));
	//hls::exp(-fp_type(1) * s)
};

template<class T, class U>
T tan(U x)
{
	//return (exp(-2*x)-1)/(exp(-2*x)+1);
	return (U(1) - U(2)*sig<fp1,fp1>(-2*x));
};
*/


/*
void loadIn(fp1 *x1, fp1 *in_stream, int *index, int seq_out)
{
	inputs1:for(int i=0;i<BATCH_SIZE*SEQ_LEN*8;i++)
	{
		if(i<((seq_out)*(8)))
		{
			x1[i] = in_stream[(*index)];
			(*index)++;
			//x2[i] = in_stream[i];
			//cout<<"x1["<<i<<"]=  " << x1[i]<< "\n";
		}
		else
			break;

	}
}

void loadWq1(fp2 *wq1_1, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
	//headq1:for(int j=0;j<NUM_HEADS;j++)
	//{
	//	if(j<(nheads_out))
	//	{
			weightQ1_1:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_1[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << i << "]=  " << wq1_1[i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq2(fp2 *wq1_2, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_2:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_2[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq3(fp2 *wq1_3, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_3:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_3[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq4(fp2 *wq1_4, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_4:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_4[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq5(fp2 *wq1_5, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_5:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_5[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq6(fp2 *wq1_6, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_6:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_6[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq7(fp2 *wq1_7, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_7:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_7[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq8(fp2 *wq1_8, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_8:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_8[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq9(fp2 *wq1_9, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_9:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_9[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq10(fp2 *wq1_10, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_10:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_10[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq11(fp2 *wq1_11, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_11:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_11[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq12(fp2 *wq1_12, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int factor)
{
			weightQ1_12:for(int i=0;i<8*EMBEDDING_DIM/(NUM_HEADS);i++)
			{
				if(i<((8)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_12[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
	//	}
	//	else
	//		break;
	//}
};


void loadWn(fp2 *gamma1, fp2 *weight_stream1, int *index, int embed_out)
{
	weight_LN1:for(int i=0;i<EMBEDDING_DIM;i++)
	{
		if(i<(embed_out))
		{
			gamma1[i] = weight_stream1[*index];
			(*index)++;
		}
		else
			break;
	}
};


void loadW1(fp2 (*w1)[EMBEDDING_DIM], fp2 *weight_stream1, int *index, int embed_out)
{
	weight1_1:for(int i=0;i<4*EMBEDDING_DIM;i++)
	{
		if(i<(4*(embed_out)))
		{
			weight1_2:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<((embed_out)))
				{
					//w1[l][i][j] = weight_stream1[index];//i*4*EMBEDDING_DIM+j+6*(*embed_out)*(*embed_out)/(*nheads_out)+(*embed_out)*(*embed_out)+(*embed_out)+l*enc_size1];
					w1[i][j] = weight_stream1[*index];//i*4*EMBEDDING_DIM+j+6*(*embed_out)*(*embed_out)/(*nheads_out)+(*embed_out)*(*embed_out)+(*embed_out)+l*enc_size1];
					//cout<<"w1[" << l << "][" << i << "][" << j << "]=  " << w1[l][i][j]<< "\n";
					(*index)++;
				}
				else
					break;
			}
		}
		else
			break;
	//		cout<<"w1["<<i<<"]=  " << w1[l][i]<< "\n";
	}
};

void loadW2(fp2 (*w2)[HIDDEN_DIM], fp2 *weight_stream1, int *index, int embed_out)
{
	weight2_1:for(int i=0;i<EMBEDDING_DIM;i++)
	{
		if(i<((embed_out)))
		{
			weight2_2:for(int j=0;j<4*EMBEDDING_DIM;j++)
			{
				if(j<(4*(embed_out)))
				{
					//w2[l][i][j] = weight_stream1[index];//i*EMBEDDING_DIM+j+6*(*embed_out)*(*embed_out)/(*nheads_out)+5*(*embed_out)*(*embed_out)+(*embed_out)+l*enc_size1];
					w2[i][j] = weight_stream1[*index];//i*EMBEDDING_DIM+j+6*(*embed_out)*(*embed_out)/(*nheads_out)+5*(*embed_out)*(*embed_out)+(*embed_out)+l*enc_size1];
					//cout<<"w2[" << l << "][" << i << "][" << j << "]=  " << w2[l][i][j]<< "\n";
					(*index)++;
				}
			}

		}
		else
			break;
	//		cout<<"w2["<<i<<"]=  " << w2[l][i]<< "\n";
	}
};
*/

/*

void loadBq1(fp2 *bq1,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{

			query_bias1:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq1[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq2(fp2 *bq2, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias2:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq2[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq3(fp2 *bq3, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias3:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq3[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq4(fp2 *bq4, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias4:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq4[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq5(fp2 *bq5, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias5:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq5[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq6(fp2 *bq6, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias6:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq6[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq7(fp2 *bq7, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias7:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq7[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq8(fp2 *bq8, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias8:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq8[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq9(fp2 *bq9, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias9:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq9[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq10(fp2 *bq10, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias10:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq10[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq11(fp2 *bq11, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias11:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq11[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq12(fp2 *bq12, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias12:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq12[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}



	//	}
	//	else
	//		break;
	//}
};

void loadBiasAll(fp2 *beta2, fp2 *bias_stream, int *index2, int embed_out)
{
	encode_bias:for(int j=0;j<EMBEDDING_DIM;j++)
	{
		if(j<(embed_out))
		{
			//beta2[l][j] = bias_stream[index2];
			beta2[j] = bias_stream[*index2];
			*index2 = *index2+1;
		}
		else
			break;
	}
};

void loadBiasInter(fp2 *beta2, fp2 *bias_stream, int *index2, int hidden_out)
{
	encode_bias:for(int j=0;j<HIDDEN_DIM;j++)
	{
		if(j<(hidden_out))
		{
			//beta2[l][j] = bias_stream[index2];
			beta2[j] = bias_stream[*index2];
			*index2 = *index2+1;
		}
		else
			break;
	}
};

// ADD & NORMALIZE-01
void addNorm1(fp3 (*ff_out1)[EMBEDDING_DIM], fp1 *x1, int seq_out, int embed_out)
{
	add_norm_seq1: for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<(seq_out))
		{
			add_norm_embed1: for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out))
				{
					ff_out1[i][j] = ff_out1[i][j]+x1[i*(embed_out)+j];
				}
				else
					break;
			}
		}
		else
			break;
	}
};

// ADD & NORMALIZE-02
void addNorm2(fp3 (*ff_out2)[EMBEDDING_DIM], fp1 (*LN_out1)[EMBEDDING_DIM], int seq_out, int embed_out)
{
	add_norm_seq2: for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<(seq_out))
		{
			add_norm_embed2: for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<(embed_out))
				{
					ff_out2[i][j] = ff_out2[i][j]+LN_out1[i][j];
				}
				else
					break;
			}
		}
		else
			break;
	}
};
*/
