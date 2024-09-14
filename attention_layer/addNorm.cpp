#include "addNorm.h"
#include "TNN_5_2.h"

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
