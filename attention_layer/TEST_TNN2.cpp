//#include <fstream>
#include "TNN_5.h"
#include "data.h"
#include <iostream>
using namespace std;
//#include "inputs.h"
//#include "pooler.h"
//#include "encoder0.h"
//#include "encoder1.h"
//#include "encoder2.h"
/*
#include "encoder3.h"
#include "encoder4.h"
#include "encoder5.h"
#include "encoder6.h"
#include "encoder7.h"
#include "encoder8.h"
#include "encoder9.h"
#include "encoder10.h"
#include "encoder11.h"
#include "classifier.h"*/
//#include "test_encode.cpp"

//void myprint();
//void encode0();

int main()
{
	//int w_index1;
	//int b_index1;
	int i,j,k,l,m;
	int i_index = 0;

	int done = 0;
//	int3 new_net = 1;
	//new_net1 = 1;
	//new_net = &new_net1;


	int h;
	float correct = 0;


	int SEQ1 = 4;//16;//64;//2;//2//128
	int BATCH1 = 1;
	int EMBEDDING1 = 4;//128;//4;//8//512
	int HEADS1 = 8;//2;//8
	int HIDDEN_D1 = 4*EMBEDDING1;//16; //2048
    int OUTPUT_D1 = EMBEDDING1;//530;//1000
    int ENCODER_LAYERS1 = 1;//4;
    int LABEL1 = 2;
    int TILE1 = EMBEDDING1;

    fp3 Output[SEQ1*LABEL1];
//-----------------------------Configure registers ----------------------------------
    encoder_layer1(SEQ1, EMBEDDING1, HEADS1, HIDDEN_D1, TILE1);
/*  encoder_layer2();
    encoder_layer3();
    encoder_layer4();
    encoder_layer5();
    encoder_layer6();
    encoder_layer7();
    encoder_layer8();
    encoder_layer9();
    encoder_layer10();
    encoder_layer11();
    encoder_layer12();*/

	cout << "w index 1:" << w_index1 << "\n";
	cout << "b index 1:" << b_index1 << "\n";
	for(m=0;m<EMBEDDING1/TILE1;m++)//for(m=0;m<EMBEDDING/TILE_SIZE;m++)
	{
		for(j=0;j<SEQ1;j++)
		{
			for(i=0;i<TILE1;i++)
			{
				inStream[i_index] = inputs[j][m*TILE1+i]; //TILE_SIZE
				i_index = i_index+1;
				//cout<<"in_stream["<< j*EMBEDDING+i <<"]=  " << inStream[j*EMBEDDING+i] << "\n";
			}
			// cout<<"in_stream["<< j*EMBEDDING+i-1 <<"]=  " << in_stream[j*EMBEDDING+i-1]<< "\n";
		}
	}

	for(i=0;i<EMBEDDING1;i++)//for(i=0;i<EMBEDDING_DIM;i++)
 	{
 		 for(j=0;j<EMBEDDING1;j++) //EMBEDDING_DIM
 		 {
 			weight_stream2[i*EMBEDDING1+j] = pool_weight[i][j]; //EMBEDDING_DIM
 			//cout<<"weight_stream2["<< i*EMBEDDING_DIM+j <<"]=  " << weight_stream2[i*EMBEDDING_DIM+j]<< "\n";
 		 }
 	}
	for(i=0;i<LABEL1;i++) //NUM_LABELS
 	{
 		 for(j=0;j<EMBEDDING1;j++)
 		 {
 			weight_stream3[i*EMBEDDING1+j] = classify_weight[i][j];
// 			cout<<"weight_stream3["<< i*EMBEDDING_DIM+j <<"]=  " << weight_stream3[i*EMBEDDING_DIM+j]<< "\n";
 		 }
 	}

	 for(j=0;j<EMBEDDING1;j++)
	 {
		 bias_stream2[j] = pool_bias[j];
		 //cout<<"bias_stream["<<j+b_index1<<"]=  " << bias_stream[j+b_index1] << "\n";

	 }
	 //b_index1 = b_index1+j;

	 for(j=0;j<LABEL1;j++)
	 {
		 bias_stream2[j+EMBEDDING1] = classify_bias[j];
		 //cout<<"bias_stream["<<j+b_index1<<"]=  " << bias_stream[j+b_index1] << "\n";

	 }

/*	 for(j=0;j<NUM_ENCODER_LAYERS*(7*EMBEDDING_DIM+HIDDEN_DIM);j++)
	 {
		 cout<<"bias_stream["<<j<<"]=  " << bias_stream[j] << "\n";
	 }
*/

	 cout<<" done before: " << done << "\n";

	 TNN(&BATCH1, &LABEL1, &SEQ1, &HEADS1, &ENCODER_LAYERS1, &EMBEDDING1, &HIDDEN_D1, &OUTPUT_D1, &TILE1, &done, inStream, bias_stream, bias_stream2, weight_stream1, weight_stream2, weight_stream3, out_stream);

	 cout<<" done after: " << done << "\n";


	for(k=0;k<SEQ1*LABEL1;k++)//SEQ_LEN*NUM_LABELS
	{
		Output[k] = out_stream[k] ;
		cout<<"Output["<<k<<"]=  " << Output[k] << "\n";
	}

	//		cout<<"Output["<<0<<"]=  " << Output[0] << "\n";

/*
    	for(i=0;i<EMBEDDING;i++)
    	{
    		//inStream[j*EMBEDDING+i] = inputs[j][i];
    		cout<<"bias_stream["<< i <<"]=  " << bias_stream[i] << "\n";
    	}
    	// cout<<"in_stream["<< j*EMBEDDING+i-1 <<"]=  " << in_stream[j*EMBEDDING+i-1]<< "\n";


	//in_stream[0] = input_arr[P];

	 int index = 0;

	 // QUERY

		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<EMBEDDING;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j] = query0[i][k*HEADS+j];
					index = index+1;
					//cout<<"weight_stream1["<<k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j<<"]=  " << weight_stream1[k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j]<< "\n";
				}

			 }
		 }


	// KEY
		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<EMBEDDING;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j+index] = key0[i][k*HEADS+j];
					index = index+1;
				}
			//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
			 }
		 }


	// VALUE
		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<EMBEDDING;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j+index] = value0[i][k*HEADS+j];
					index = index+1;
				}
			//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
			 }
		 }

	// Attention Weight
		 for(i=0;i<EMBEDDING;i++)
		 {
			for(j=0;j<EMBEDDING;j++)
			{
				weight_stream1[i*EMBEDDING+j+index] = attention_weight0[i][j];
				index = index+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		 }

	// Attention LN1 Weight

		 for(j=0;j<EMBEDDING;j++)
		 {
				weight_stream1[i*EMBEDDING+j+index] = attention_LN_weight0[j];
				index = index+1;
		 }
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";

	// Encode Intermediate Weight

		for(i=0;i<HIDDEN_D;i++)
		{
			for(j=0;j<EMBEDDING;j++)
			{
				weight_stream1[i*EMBEDDING+j+index] = encode_intermediate_weight0[i][j];
				index = index+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		}

		for(i=0;i<EMBEDDING;i++)
		{
			for(j=0;j<HIDDEN_D;j++)
			{
				weight_stream1[i*EMBEDDING+j+index] = encode_out_weight0[i][j];
				index = index+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		}

	// Encode LN Weight

		for(j=0;j<EMBEDDING;j++)
		{
			weight_stream1[i*EMBEDDING+j+index] = encode_LN_weight0[j];
			index = index+1;
		}

		/*
			for(i=0;i<EMBEDDING*OUTPUT_D;i++)
			{

				weight_stream2[i] = w_all[i+12*ENCODER_LAYERS*EMBEDDING*EMBEDDING];
//				cout<<"weight_stream2["<<i<<"]=  " << weight_stream2[i]<< "\n";
			}



*/
   		return 0;
}
