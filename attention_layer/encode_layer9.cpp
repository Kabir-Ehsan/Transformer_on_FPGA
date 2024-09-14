#include "TNN_5_2.h"
#include "data.h"
#include "iostream"
using namespace std;

void encoder_layer9()
{

	 int i,j,k,l,m;


	 cout << "Encoder Layer 9 File" << "\n";
	 // QUERY
	for(m=0;m<EMBEDDING/TILE_SIZE;m++)
	{
		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<TILE_SIZE;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[w_index1] = query8[m*TILE_SIZE+i][k*EMBEDDING/HEADS+j];
					w_index1 = w_index1+1;
					//cout<<"weight_stream1["<<k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j<<"]=  " << weight_stream1[k*EMBEDDING*EMBEDDING/HEADS+i*EMBEDDING/HEADS+j]<< "\n";
				}

			 }
		 }


	// KEY
		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<TILE_SIZE;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[w_index1] = key8[m*TILE_SIZE+i][k*EMBEDDING/HEADS+j];
					w_index1 = w_index1+1;
				}
			//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
			 }
		 }


	// VALUE
		 for(k=0;k<HEADS;k++)
		 {
			 for(i=0;i<TILE_SIZE;i++)
			 {
				for(j=0;j<EMBEDDING/HEADS;j++)
				{
					weight_stream1[w_index1] = value8[m*TILE_SIZE+i][k*EMBEDDING/HEADS+j];
					w_index1 = w_index1+1;
				}
			//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
			 }
		 }
	}

	// Attention Weight
		 for(i=0;i<EMBEDDING;i++)
		 {
			for(j=0;j<EMBEDDING;j++)
			{
				weight_stream1[w_index1] = attention_weight8[i][j];
				w_index1 = w_index1+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		 }

	// Attention LN1 Weight

		 for(j=0;j<EMBEDDING;j++)
		 {
				weight_stream1[w_index1] = attention_LN_weight8[j];
				w_index1 = w_index1+1;
		 }
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";

	// Encode Intermediate Weight

		for(i=0;i<HIDDEN_D;i++)
		{
			for(j=0;j<EMBEDDING;j++)
			{
				weight_stream1[w_index1] = encode_intermediate_weight8[i][j];
				w_index1 = w_index1+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		}

		// Encode out Weight
		for(i=0;i<EMBEDDING;i++)
		{
			for(j=0;j<HIDDEN_D;j++)
			{
				weight_stream1[w_index1] = encode_out_weight8[i][j];
				w_index1 = w_index1+1;
			}
		//cout<<"weight_stream1["<<i<<"]=  " << weight_stream1[i]<< "\n";
		}

		// Encode LN Weight

		for(j=0;j<EMBEDDING;j++)
		{
			weight_stream1[w_index1] = encode_LN_weight8[j];
			w_index1 = w_index1+1;
		}
		// query_bias

		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = query_bias8[j];
			b_index1 = b_index1+1;
		}
		// key_bias

		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = key_bias8[j];
			b_index1 = b_index1+1;
		}
		// value_bias

		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = value_bias8[j];
			b_index1 = b_index1+1;
		}
		// attention_bias
		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = attention_bias8[j];
			b_index1 = b_index1+1;
		}

		// attention_LN_bias
		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = attention_LN_bias8[j];
			b_index1 = b_index1+1;
		}

		// intermediate bias
		for(j=0;j<HIDDEN_D;j++)
		{
			bias_stream[b_index1] = encode_intermediate_bias8[j];
			b_index1 = b_index1+1;
		}

		// encode out bias
		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = encode_out_bias8[j];
			b_index1 = b_index1+1;
		}

		// encode LN bias
		for(j=0;j<EMBEDDING;j++)
		{
			bias_stream[b_index1] = encode_LN_bias8[j];
			//cout<<"bias_stream["<<j+b_index1+b_index2+b_index3+b_index4+b_index5+b_index6+b_index7+b_index8<<"]=  " << bias_stream[j+b_index1+b_index2+b_index3+b_index4+b_index5+b_index6+b_index7+b_index8] << "\n";
			b_index1 = b_index1+1;
		}


};
