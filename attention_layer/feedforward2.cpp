#include "feedforward2.h"
#include "TNN_5.h"

/*
void feedforward2(fp1 (*in)[fact1], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[fact1], int *index, int s, int n, int k)
{
  //cout<< "feed forward 1 start" << '\n';
  int m;
  fp3 sum = 0;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  m = (*index)*k;
		  col1:for (int i = 0; i<fact1; i++) //530
		  {
			  if(i<k)
			  {
				  sum = 0;
				  row1:for (int j = 0; j<fact1; j++) //4
				  {
					  if(j<n)
					  {
						  sum += in[l][j] * w1[i][j];
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
*/

void feedforward2(fp1 (*in)[EMBEDDING_DIM], fp3 (*out)[HIDDEN_DIM], fp2 (*w1)[EMBEDDING_DIM], int *index, int s, int n, int k)
{
  //cout<< "feed forward 1 start" << '\n';
  int m;
  fp3 sum = 0;
  seq1:for(int l=0; l<SEQ_LEN; l++)
  {
	  if(l<s)
	  {
		  m = (*index)*k;
		  col1:for (int i = 0; i<EMBEDDING_DIM; i++) //530
		  {
			  if(i<k)
			  {
				  sum = 0;
				  row1:for (int j = 0; j<EMBEDDING_DIM; j++) //4
				  {
					  if(j<n)
					  {
						  sum += in[l][j] * w1[i][j];
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

