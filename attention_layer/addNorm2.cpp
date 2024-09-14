#include "addNorm2.h"
#include "TNN_5_2.h"
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
