#include "softmax.h"
#include "TNN_5_2.h"

void softmax(fp1 (*x)[SEQ_LEN], int n, int d, int t) //fp1 (*x)[EMBEDDING_DIM/NUM_HEADS]
{
  fp3 maxval = -INFINITY;
  fp3 sum = 0.0;
  loop1:for (int i = 0; i < (SEQ_LEN); i++)  //
  {
	  if(i<n)
	  {
		  loop1_2: for (int j = 0; j < SEQ_LEN ; j++) //(EMBEDDING_DIM/NUM_HEADS)
		  {
			  if(j<n)//d/t)
			  {
				  if (x[i][j] > maxval)
				  {
					  maxval = x[i][j];
				  }
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
  loop2:for (int i = 0; i < (SEQ_LEN); i++)
  {
	  if(i<n)
	  {
		  loop2_1: for (int j = 0; j < SEQ_LEN; j++) //(EMBEDDING_DIM/NUM_HEADS)
		  {
			  if(j<n)//d/t)
			  {
				  	  x[i][j] = hls::exp(x[i][j] - maxval); //expf
				  	  sum += x[i][j];
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
  loop3:for (int i = 0; i < (SEQ_LEN); i++)
  {
	  if(i<n)
	  {
		  loop3_1: for (int j = 0; j < SEQ_LEN; j++) //(EMBEDDING_DIM/NUM_HEADS)
		  {
			  if(j<n)//d/t)
			  {
				  x[i][j] /= sum;
			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }
};
