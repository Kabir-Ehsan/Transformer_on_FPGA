#include "loadWo2.h"
#include "TNN_5_2.h"

void loadWo(fp2 (*wo1)[fact6], fp2 *weight_stream1, int *index, int embed_out, int nheads_out, int factor)
{
	weightO1:for(int i=0;i<fact6;i++)
	{
		if(i<factor)//(embed_out/nheads_out))
		{
			weightO2:for(int j=0;j<fact5;j++)
			{
				if(j<factor)//(embed_out/nheads_out))
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
/*
void loadWo(fp2 (*wo1)[EMBEDDING_DIM], fp2 *weight_stream1, int *index, int embed_out, int nheads_out, int factor)
{
	weightO1:for(int i=0;i<EMBEDDING_DIM;i++)
	{
		if(i<factor)//(embed_out/nheads_out))
		{
			weightO2:for(int j=0;j<EMBEDDING_DIM;j++)
			{
				if(j<factor)//(embed_out/nheads_out))
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
*/
