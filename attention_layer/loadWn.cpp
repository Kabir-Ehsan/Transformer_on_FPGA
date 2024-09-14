#include "loadWn.h"
#include "TNN_5_2.h"


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
