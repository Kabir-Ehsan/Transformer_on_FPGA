#include "loadBiasInter.h"
#include "TNN_5_2.h"

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
