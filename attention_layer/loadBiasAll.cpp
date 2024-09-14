#include "loadBiasAll.h"
#include "TNN_5_2.h"

void loadBiasAll(fp2 *beta2, fp2 *bias_stream, int *index2, int embed_out)
{
	encode_bias_all:for(int j=0;j<EMBEDDING_DIM;j++)
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
