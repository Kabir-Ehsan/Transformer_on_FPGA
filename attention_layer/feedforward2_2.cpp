#include "feedforward2_2.h"
#include "TNN_5_2.h"

//void feedforward2(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[fact6], int *index, int s, int n, int k)
void feedforward2(fp1 (*in)[fact6], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[fact6], int *index, int s, int n, int k)
{
  //cout<< "feed forward 1 start" << '\n';
  int m;
  fp3 sum = 0.0;
  seq2:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  m =  (*index)*k;
		  col2:for (int i = 0; i<fact6; i++) //530
		  {
			  if(i<k)
			  {
				  sum = 0.0;
				  row2:for (int j = 0; j<fact5; j++) // fact5 for EMBEDDING_DIM
				  {
					  if(j<n)
					  {
						  sum = sum + in[l][j] * w1[j][i];
						  //out[l][(*index)*k+i] += in[l][j] * w1[j][i];
						  //cout<< "out :" << l << "," << (*index)*n+i << " : " << out[l][(*index)*n+i] << "\n" ;
					  }
					  else
						  break;
				  }

				  out[l][m] += sum;
				  m++;

			  }
			  else
				  break;
		  }
	  }
	  else
		  break;
  }

};
