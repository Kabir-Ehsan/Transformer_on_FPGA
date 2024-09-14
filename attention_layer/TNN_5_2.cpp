#include "TNN_5_2.h"
//#include "addNorm2.h"
//#include "addNorm.h"
//#include "loadBiasInter.h"
//#include "loadBiasAll.h"
#include "loadBq.h"
#include "loadWq.h"
//#include "loadWn.h"
#include "loadIn2.h"
#include "softmax.h"
#include "activation.h"
//#include "layerNorm.h"
#include "score.h"
//#include "loadWo2.h"
#include "biasAdd.h"
#include "self_attention.h"
//#include "feedforward1_2.h"
//#include "feedforward2_2.h"
//#include "feedforward_last.h"

#include <iostream>

using namespace std;

void TNN(int *batch, int *labels, int *seq_out, int *nheads_out, int *nlayers_out, int *embed_out, int *hidden_out, int *outdim_out, int *tile, int *over, fp1 in_stream[BATCH_SIZE*SEQ_LEN*EMBEDDING_DIM], fp2 bias_stream[NUM_ENCODER_LAYERS*(4*EMBEDDING_DIM+HIDDEN_DIM)], fp2 bias_stream2[EMBEDDING_DIM+OUTPUT_DIM], fp2 weight_streamQ1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV1[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV2[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV3[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV4[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)],
		fp2 weight_streamQ5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamQ8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamK8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV5[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV6[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV7[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)], fp2 weight_streamV8[NUM_ENCODER_LAYERS*(EMBEDDING_DIM*fact1)],
		fp2 bias_streamQ1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ4[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamQ8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamK1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK4[NUM_ENCODER_LAYERS*(fact1)],	fp2 bias_streamK5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamK8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 bias_streamV1[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV2[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV3[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV4[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV5[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV6[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV7[NUM_ENCODER_LAYERS*(fact1)], fp2 bias_streamV8[NUM_ENCODER_LAYERS*(fact1)],
		fp2 weight_stream1[NUM_ENCODER_LAYERS*(9*EMBEDDING_DIM*EMBEDDING_DIM+2*EMBEDDING_DIM)], fp2 weight_stream2[EMBEDDING_DIM*EMBEDDING_DIM], fp2 weight_stream3[NUM_LABELS*EMBEDDING_DIM], fp3 out_stream[SEQ_LEN*NUM_LABELS], int *tile_score1, int *tile_score2)
{
	*over = 0;
	int enc_size1 = 0;
	int i=0,k=0,l=0,m=0, w_index=0, index=0, index2=0, index3 = 0, index4=0, index5=0, index6=0, s=0, e=0;
	int j=0;
	int ii=0;


	ap_uint<10> div_factor0 = (*embed_out)/(*tile);
	ap_uint<8> div_factor1 = (*embed_out)/(*nheads_out);
	ap_uint<8> div_factor2 = (*embed_out)/(div_factor1);
	ap_uint<8> div_factor3 = (*hidden_out)/(div_factor1);
	ap_uint<16> div_factor4 = (*tile)*(div_factor1);
	ap_uint<20> div_factor5 = (*tile)*(*seq_out);

	ap_uint<8> factorsqrt = hls::sqrt(div_factor1);
	
	ap_uint<10> div_factor6 = (*embed_out)/(*tile_score2);
	ap_uint<12> div_factor7 = (*hidden_out)/(*tile_score1);

	int indexQ1=0, indexQ2=0, indexQ3=0, indexQ4=0, indexQ5=0, indexQ6=0, indexQ7=0, indexQ8=0, indexQ9=0, indexQ10=0, indexQ11=0, indexQ12=0;
	int indexK1=0, indexK2=0, indexK3=0, indexK4=0, indexK5=0, indexK6=0, indexK7=0, indexK8=0, indexK9=0, indexK10=0, indexK11=0, indexK12=0;
	int indexV1=0, indexV2=0, indexV3=0, indexV4=0, indexV5=0, indexV6=0, indexV7=0, indexV8=0, indexV9=0, indexV10=0, indexV11=0, indexV12=0;

	int indexQb1=0, indexQb2=0, indexQb3=0, indexQb4=0, indexQb5=0, indexQb6=0, indexQb7=0, indexQb8=0, indexQb9=0, indexQb10=0, indexQb11=0, indexQb12=0;
	int indexKb1=0, indexKb2=0, indexKb3=0, indexKb4=0, indexKb5=0, indexKb6=0, indexKb7=0, indexKb8=0, indexKb9=0, indexKb10=0, indexKb11=0, indexKb12=0;
	int indexVb1=0, indexVb2=0, indexVb3=0, indexVb4=0, indexVb5=0, indexVb6=0, indexVb7=0, indexVb8=0, indexVb9=0, indexVb10=0, indexVb11=0, indexVb12=0;


	int s1=0, e1=0, s2=0, e2=0, s3=0, e3=0, s4=0, e4=0, s5=0, e5=0, s6=0, e6=0, s7=0, e7=0, s8=0, e8=0, s9=0, e9=0, s10=0, e10=0, s11=0, e11=0, s12=0, e12=0;

	fp1 eps = 1e-12;

	 fp1 qq1[SEQ_LEN][fact1] = {0};
	 fp1 kk1[SEQ_LEN][fact1] = {0};
	 fp1 vv1[SEQ_LEN][fact1] = {0};

	 fp1 qq2[SEQ_LEN][fact1] = {0};
	 fp1 kk2[SEQ_LEN][fact1] = {0};
	 fp1 vv2[SEQ_LEN][fact1] = {0};

	 fp1 qq3[SEQ_LEN][fact1] = {0};
	 fp1 kk3[SEQ_LEN][fact1] = {0};
	 fp1 vv3[SEQ_LEN][fact1] = {0};

	 fp1 qq4[SEQ_LEN][fact1] = {0};
	 fp1 kk4[SEQ_LEN][fact1] = {0};
	 fp1 vv4[SEQ_LEN][fact1] = {0};

	 fp1 qq5[SEQ_LEN][fact1] = {0};
	 fp1 kk5[SEQ_LEN][fact1] = {0};
	 fp1 vv5[SEQ_LEN][fact1] = {0};

	 fp1 qq6[SEQ_LEN][fact1] = {0};
	 fp1 kk6[SEQ_LEN][fact1] = {0};
	 fp1 vv6[SEQ_LEN][fact1] = {0};

	 fp1 qq7[SEQ_LEN][fact1] = {0};
	 fp1 kk7[SEQ_LEN][fact1] = {0};
	 fp1 vv7[SEQ_LEN][fact1] = {0};

	 fp1 qq8[SEQ_LEN][fact1] = {0};
	 fp1 kk8[SEQ_LEN][fact1] = {0};
	 fp1 vv8[SEQ_LEN][fact1] = {0};
/*
	fp1 qq9[SEQ_LEN][fact1] = {0};
	fp1 kk9[SEQ_LEN][fact1] = {0};
	fp1 vv9[SEQ_LEN][fact1] = {0};

	fp1 qq10[SEQ_LEN][fact1] = {0};
	fp1 kk10[SEQ_LEN][fact1] = {0};
	fp1 vv10[SEQ_LEN][fact1] = {0};

	fp1 qq11[SEQ_LEN][fact1] = {0};
	fp1 kk11[SEQ_LEN][fact1] = {0};
	fp1 vv11[SEQ_LEN][fact1] = {0};

	fp1 qq12[SEQ_LEN][fact1] = {0};
	fp1 kk12[SEQ_LEN][fact1] = {0};
	fp1 vv12[SEQ_LEN][fact1] = {0};
*/

	 fp2  wq1_1[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_1[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_1[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_2[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_2[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_2[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_3[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_3[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_3[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_4[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_4[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_4[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_5[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_5[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_5[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_6[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_6[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_6[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_7[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_7[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_7[wfact] = {0};//*EMBEDDING_DIM];

	 fp2  wq1_8[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wk1_8[wfact] = {0};//*EMBEDDING_DIM];
	 fp2  wv1_8[wfact] = {0};//*EMBEDDING_DIM];
/*
	  fp2  wq1_9[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_9[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_9[wfact] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_10[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_10[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_10[wfact] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_11[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_11[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_11[wfact] = {0};//*EMBEDDING_DIM];

	  fp2  wq1_12[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wk1_12[wfact] = {0};//*EMBEDDING_DIM];
	  fp2  wv1_12[wfact] = {0};//*EMBEDDING_DIM];
*/
	 fp2  bq1[fact1] = {0};
	 fp2  bk1[fact1] = {0};
	 fp2  bv1[fact1] = {0};

	 fp2  bq2[fact1] = {0};
	 fp2  bk2[fact1] = {0};
	 fp2  bv2[fact1] = {0};

	 fp2  bq3[fact1] = {0};
	 fp2  bk3[fact1] = {0};
	 fp2  bv3[fact1] = {0};

	 fp2  bq4[fact1] = {0};
	 fp2  bk4[fact1] = {0};
	 fp2  bv4[fact1] = {0};

	 fp2  bq5[fact1] = {0};
	 fp2  bk5[fact1] = {0};
	 fp2  bv5[fact1] = {0};

	 fp2  bq6[fact1] = {0};
	 fp2  bk6[fact1] = {0};
	 fp2  bv6[fact1] = {0};

	 fp2  bq7[fact1] = {0};
	 fp2  bk7[fact1] = {0};
	 fp2  bv7[fact1] = {0};

	 fp2  bq8[fact1] = {0};
	 fp2  bk8[fact1] = {0};
	 fp2  bv8[fact1] = {0};
/*
	  fp2  bq9[(fact1)] = {0};
	  fp2  bk9[(fact1)] = {0};
	  fp2  bv9[(fact1)] = {0};

	  fp2  bq10[(fact1)] = {0};
	  fp2  bk10[(fact1)] = {0};
	  fp2  bv10[(fact1)] = {0};

	  fp2  bq11[(fact1)] = {0};
	  fp2  bk11[(fact1)] = {0};
	  fp2  bv11[(fact1)] = {0};

	  fp2  bq12[(fact1)] = {0};
	  fp2  bk12[(fact1)] = {0};
	  fp2  bv12[(fact1)] = {0};
*/
	  fp2  gamma1[EMBEDDING_DIM];
	  fp2  beta1[EMBEDDING_DIM];

//	  fp2  gamma2[EMBEDDING_DIM];
//	  fp2  beta2[EMBEDDING_DIM];

//	  fp2  wo1[fact5][fact6];//[EMBEDDING_DIM][EMBEDDING_DIM];//;

//	  static fp2  w1[fact1][fact1];//[4*EMBEDDING_DIM][EMBEDDING_DIM];
//	  static fp2  w2[fact1][fact1];//[EMBEDDING_DIM][4*EMBEDDING_DIM];

//	  static fp2  wp[EMBEDDING_DIM][EMBEDDING_DIM];

	   fp2 weight_class[NUM_LABELS][EMBEDDING_DIM];

	   fp1  x1[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x2[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x3[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x4[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x5[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x6[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x7[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	   fp1  x8[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
/*	  fp1  x9[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  fp1  x10[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  fp1  x11[BATCH_SIZE*SEQ_LEN*TILE_SIZE];
	  fp1  x12[BATCH_SIZE*SEQ_LEN*TILE_SIZE];*/

//	  fp3  ff_out1[SEQ_LEN][EMBEDDING_DIM]; //[BATCH_SIZE
//	  fp3  ff_out1_temp[SEQ_LEN][fact6];//EMBEDDING_DIM]; //

//      fp3  ff_out2[SEQ_LEN][HIDDEN_DIM]; //[BATCH_SIZE

//      fp3  pool_out[SEQ_LEN][EMBEDDING_DIM];

//     fp3  LN_out1[SEQ_LEN][EMBEDDING_DIM]; //[BATCH_SIZE


//    fp2  bff_1[EMBEDDING_DIM] = {0};
//    fp2  bff_2[HIDDEN_DIM] = {0};
//    fp2  bff_3[EMBEDDING_DIM] = {0};

      fp2  bp[EMBEDDING_DIM] = {0};
      fp2  bclass[OUTPUT_DIM] = {0};

      fp2  bout[SEQ_LEN*OUTPUT_DIM] = {0};
      fp2  vs[SEQ_LEN][EMBEDDING_DIM];

       fp2 vs1[SEQ_LEN][fact1];
       fp2 vs2[SEQ_LEN][fact1];
       fp2 vs3[SEQ_LEN][fact1];
       fp2 vs4[SEQ_LEN][fact1];
       fp2 vs5[SEQ_LEN][fact1];
       fp2 vs6[SEQ_LEN][fact1];
       fp2 vs7[SEQ_LEN][fact1];
       fp2 vs8[SEQ_LEN][fact1];
/*    fp2 vs9[SEQ_LEN][fact1];
      fp2 vs10[SEQ_LEN][fact1];
      fp2 vs11[SEQ_LEN][fact1];
      fp2 vs12[SEQ_LEN][fact1];*/

      fp2 vs_temp[SEQ_LEN][fact6];//EMBEDDING_DIM];//
      fp3 out_temp[SEQ_LEN][NUM_LABELS];


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
// 			cout<<"weight_out["<<i<<"]=  " << weight_out[i]<< "\n";
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
 		if(i<(*outdim_out))
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

		loadBias_loop:
		{
			loadBq1(bq1, bias_streamQ1, &indexQb1, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq2(bq2, bias_streamQ2, &indexQb2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq3(bq3, bias_streamQ3, &indexQb3, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq4(bq4, bias_streamQ4, &indexQb4, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq5(bq5, bias_streamQ5, &indexQb5, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq6(bq6, bias_streamQ6, &indexQb6, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq7(bq7, bias_streamQ7, &indexQb7, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq8(bq8, bias_streamQ8, &indexQb8, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			/*			loadBq9(bq9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq10(bq10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq11(bq11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq12(bq12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
*/
			loadBq1(bk1, bias_streamK1, &indexKb1, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq2(bk2, bias_streamK2, &indexKb2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq3(bk3, bias_streamK3, &indexKb3, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq4(bk4, bias_streamK4, &indexKb4, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq5(bk5, bias_streamK5, &indexKb5, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq6(bk6, bias_streamK6, &indexKb6, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq7(bk7, bias_streamK7, &indexKb7, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq8(bk8, bias_streamK8, &indexKb8, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			/*			loadBq9(bk9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq10(bk10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq11(bk11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq12(bk12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
*/
			loadBq1(bv1, bias_streamV1, &indexVb1, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq2(bv2, bias_streamV2, &indexVb2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq3(bv3, bias_streamV3, &indexVb3, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq4(bv4, bias_streamV4, &indexVb4, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq5(bv5, bias_streamV5, &indexVb5, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq6(bv6, bias_streamV6, &indexVb6, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
				loadBq7(bv7, bias_streamV7, &indexVb7, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq8(bv8, bias_streamV8, &indexVb8, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			/*			loadBq9(bv9, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq10(bv10, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq11(bv11, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
			loadBq12(bv12, bias_stream, &index2, ((*nheads_out)), ((*embed_out)), (int)div_factor1);
*/
		}
				Tiles:for(j=0;j<EMBEDDING_DIM/TILE_SIZE;j++)
				{
					if(j<((int)div_factor0))
					{

							//loadIn(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, in_stream, &index3, *seq_out, *tile, (int)div_factor5);
							//loadIn(x1, x2, x3, x4, x5, x6, in_stream, &index3, *seq_out, *tile, (int)div_factor5);
							loadIn(x1, x2, x3, x4, x5, x6, x7, x8, in_stream, &index3, *seq_out, *tile, (int)div_factor5);
							//loadIn(x1, x2, x3, in_stream, &index3, *seq_out, *tile, (int)div_factor5);

							loadWq1(wq1_1, weight_streamQ1, &indexQ1, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq2(wq1_2, weight_streamQ2, &indexQ2, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq3(wq1_3, weight_streamQ3, &indexQ3, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq4(wq1_4, weight_streamQ4, &indexQ4, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq5(wq1_5, weight_streamQ5, &indexQ5, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq6(wq1_6, weight_streamQ6, &indexQ6, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq7(wq1_7, weight_streamQ7, &indexQ7, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq8(wq1_8, weight_streamQ8, &indexQ8, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							/*							loadWq9(wq1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq10(wq1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq11(wq1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
							loadWq12(wq1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)), *tile, (int)div_factor4);
*/

							loadWq1(wk1_1, weight_streamK1, &indexK1, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq2(wk1_2, weight_streamK2, &indexK2, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq3(wk1_3, weight_streamK3, &indexK3, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq4(wk1_4, weight_streamK4, &indexK4, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq5(wk1_5, weight_streamK5, &indexK5, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq6(wk1_6, weight_streamK6, &indexK6, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq7(wk1_7, weight_streamK7, &indexK7, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq8(wk1_8, weight_streamK8, &indexK8, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							/*							loadWq9(wk1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq10(wk1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq11(wk1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq12(wk1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
*/

							loadWq1(wv1_1, weight_streamV1, &indexV1, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq2(wv1_2, weight_streamV2, &indexV2, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq3(wv1_3, weight_streamV3, &indexV3, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq4(wv1_4, weight_streamV4, &indexV4, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq5(wv1_5, weight_streamV5, &indexV5, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq6(wv1_6, weight_streamV6, &indexV6, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq7(wv1_7, weight_streamV7, &indexV7, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq8(wv1_8, weight_streamV8, &indexV8, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							/*							loadWq9(wv1_9, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq10(wv1_10, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq11(wv1_11, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
							loadWq12(wv1_12, weight_stream1, &index, ((*nheads_out)), ((*embed_out)),  *tile, (int)div_factor4);
*/
					attention_loop:
					{
						self_attention1(x1, wq1_1, wk1_1, wv1_1, qq1, kk1, vv1, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention2(x2, wq1_2, wk1_2, wv1_2, qq2, kk2, vv2, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention3(x3, wq1_3, wk1_3, wv1_3, qq3, kk3, vv3, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention4(x4, wq1_4, wk1_4, wv1_4, qq4, kk4, vv4, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention5(x5, wq1_5, wk1_5, wv1_5, qq5, kk5, vv5, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention6(x6, wq1_6, wk1_6, wv1_6, qq6, kk6, vv6, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention7(x7, wq1_7, wk1_7, wv1_7, qq7, kk7, vv7, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
						self_attention8(x8, wq1_8, wk1_8, wv1_8, qq8, kk8, vv8, *seq_out, ((*embed_out)), *nheads_out, *tile, (int)div_factor1);
/*						self_attention9(x9, wq1_9, wk1_9, wv1_9, qq9, kk9, vv9, *seq_out, ((*embed_out)), *nheads_out,  *tile, (int)div_factor1);
						self_attention10(x10, wq1_10, wk1_10, wv1_10, qq10, kk10, vv10, *seq_out, ((*embed_out)), *nheads_out,  *tile, (int)div_factor1);
						self_attention11(x11, wq1_11, wk1_11, wv1_11, qq11, kk11, vv11, *seq_out, ((*embed_out)), *nheads_out,  *tile, (int)div_factor1);
						self_attention12(x12, wq1_12, wk1_12, wv1_12, qq12, kk12, vv12, *seq_out, ((*embed_out)), *nheads_out,  *tile, (int)div_factor1);
*/
					}
				}
				else
					break;
			}



			biasAdd_loop:
			{
				biasAdd(qq1, kk1, vv1, bq1, bk1, bv1, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq2, kk2, vv2, bq2, bk2, bv2, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq3, kk3, vv3, bq3, bk3, bv3, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq4, kk4, vv4, bq4, bk4, bv4, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq5, kk5, vv5, bq5, bk5, bv5, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq6, kk6, vv6, bq6, bk6, bv6, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq7, kk7, vv7, bq7, bk7, bv7, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq8, kk8, vv8, bq8, bk8, bv8, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
/*				biasAdd(qq9, kk9, vv9, bq9, bk9, bv9, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq10, kk10, vv10, bq10, bk10, bv10, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq11, kk11, vv11, bq11, bk11, bv11, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
				biasAdd(qq12, kk12, vv12, bq12, bk12, bv12, *seq_out, ((*embed_out)), *nheads_out, (int)div_factor1);
*/
			}
			attention_score_loop:
			{
					attention_score(qq1,  kk1, vv1, vs1, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score2(qq2,  kk2, vv2, vs2, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score3(qq3,  kk3, vv3, vs3, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score4(qq4,  kk4, vv4, vs4, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score5(qq5,  kk5, vv5, vs5, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score6(qq6,  kk6, vv6, vs6, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score7(qq7,  kk7, vv7, vs7, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score8(qq8,  kk8, vv8, vs8, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
/*					attention_score9(qq9,  kk9, vv9, vs9, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score10(qq10, kk10, vv10, vs10, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score11(qq11, kk11, vv11, vs11, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
					attention_score12(qq12, kk12, vv12, vs12, *seq_out, (*embed_out),  *nheads_out, (int)div_factor1, (int)factorsqrt); //*seq_out, (*embed_out),
*/
			}

					concat1: for(i=0;i<SEQ_LEN;i++)
					{
						if(i<(*seq_out))
						{
							concat2: for(j=0; j<(fact1); j++)
							{
								if(i<(div_factor1))//(*embed_out)/(*nheads_out)))
								{
									vs[i][j] = vs1[i][j];
									vs[i][1*fact1+j] = vs2[i][j];
									vs[i][2*fact1+j] = vs3[i][j];
								 	vs[i][3*fact1+j] = vs4[i][j];
									vs[i][4*fact1+j] = vs5[i][j];
									vs[i][5*fact1+j] = vs6[i][j];
								    vs[i][6*fact1+j] = vs7[i][j];
									vs[i][7*fact1+j] = vs8[i][j];
/*									vs[i][8*fact1+j] = vs9[i][j];
									vs[i][9*fact1+j] = vs10[i][j];
									vs[i][10*fact1+j] = vs11[i][j];
									vs[i][11*fact1+j] = vs12[i][j];
*/
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


		finalLoop1: for(i=0;i<SEQ_LEN;i++)
		{
			if(i<(*seq_out))
			{
				finalLoop2: for(j=0;j<EMBEDDING_DIM;j++)
				{
					if(j<(*embed_out))
					{
						out_stream[i*(*embed_out)+j] = vs[i][j];
						//cout<< "out_stream[" << i*(*labels)+j << "] :" << out_stream[i*(*labels)+j] << "\n" ;
					}
					else
						break;
				}
			}
			else
				break;
		}

		if(i==(*seq_out))
		{
			*over = 1;
			//cout<< "over::::" <<  *over  << "\n";
		}

		return;

};

