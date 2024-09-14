#include "feedforward_last.h"
#include "TNN_5_2.h"

void feedforward_last(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[NUM_LABELS], fp2 (*w1)[EMBEDDING_DIM], fp2* b1, int n, int k, int s)
{
  //cout<< "feed forward 1 start" << '\n';
  //int m;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  col1:for (int i = 0; i<NUM_LABELS; i++) //530
		  {
			  //m = 0;
			  if(i<k)
			  {
				  row1:for (int j = 0; j<EMBEDDING_DIM; j++) //4
				  {
					  if(j<n)
					  {
						  out[l][i] += in[l][j] * w1[i][j];
						  //cout<< "in[" << l << "][" << j << "] :" << in[l][j] << "\n" ;
						  //cout<< "out[" << l << "][" << i << "] :" << out[l][i] << "\n" ;
						  //cout<< "w1[" << i << "][" << j << "] :" << w1[i][j] << "\n" ;
					  }
					  else
						  break;
	//				  	  cout<< "in" << l*n+j << ":" << in[l*n+j] << "\n" ;
				  //m++;
				  }
				  out[l][i] += b1[i];
				  //cout<< "out[" << l << "][" << i << "] :" << out[l][i] << "\n" ;
			  }
			  else
				  break;
				  //cout<< "Final_OUT" << l*k+i << ":" << out[l*k+i] << "\n";
			  //out[i] = relu(out[i]);
		  }
	  }
	  else
		  break;
  }
  //softmax(out, n);

  //free(h);
};
