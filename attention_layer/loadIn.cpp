#include "loadIn.h"
#include "TNN_5.h"

//void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, fp1 *x9, fp1 *x10, fp1 *in_stream, int *index, int seq_out, int tile) // fp1 *x11, fp1 *x12,
void loadIn(fp1 *x1, fp1 *x2, fp1 *x3, fp1 *x4, fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, fp1 *x9, fp1 *x10,  fp1 *x11,  fp1 *x12, fp2 *in_stream, int *index, int seq_out, int tile, int factor) // fp1 *x5, fp1 *x6, fp1 *x7, fp1 *x8, *x11, fp1 *x12,
{
	inputs1:for(int i=0;i<BATCH_SIZE*SEQ_LEN*TILE_SIZE;i++)
	{
		if(i<factor)
		{
			x1[i] = in_stream[(*index)];
			x2[i] = in_stream[(*index)];
			x3[i] = in_stream[(*index)];
			x4[i] = in_stream[(*index)];
			x5[i] = in_stream[(*index)];
			x6[i] = in_stream[(*index)];
			x7[i] = in_stream[(*index)];
			x8[i] = in_stream[(*index)];
			x9[i] = in_stream[(*index)];
			x10[i] = in_stream[(*index)];
			x11[i] = in_stream[(*index)];
			x12[i] = in_stream[(*index)];
			(*index)++;
			//x2[i] = in_stream[i];
			//cout<<"x1["<<i<<"]=  " << x1[i]<< "\n";
			//cout<<"x2["<<i<<"]=  " << x2[i]<< "\n";
		}
		else
			break;

	}
};
/*
void loadIn2(fp2 (*x1)[fact1], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<fact1; j++)
			{
				if(j<factor)//(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(factor)+j];
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
*/
void loadIn2(fp2 (*x1)[EMBEDDING_DIM], fp1 (*in_stream)[EMBEDDING_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<EMBEDDING_DIM; j++)
			{
				if(j<factor)//(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(factor)+j];
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
/*
void loadIn3(fp3 (*x1)[fact1], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<fact1; j++)
			{
				if(j<factor)//(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(factor)+j];
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
*/
void loadIn3(fp3 (*x1)[EMBEDDING_DIM], fp3 (*in_stream)[HIDDEN_DIM], int *index, int seq_out, int embed_out, int nheads_out, int factor)
{
	inputs1:for(int i=0;i<SEQ_LEN;i++)
	{
		if(i<seq_out)
		{
			inputs2:for(int j=0; j<EMBEDDING_DIM; j++)
			{
				if(j<factor)//(embed_out/nheads_out))
				{
					x1[i][j] = in_stream[i][(*index)*(factor)+j];
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
