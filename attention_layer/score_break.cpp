#include "score.h"
#include "softmax.h"
#include "TNN_5.h"

void attention_score(fp1 (*qq)[EMBEDDING_DIM/NUM_HEADS],  fp1 (*kk)[EMBEDDING_DIM/NUM_HEADS], fp1 (*vv)[EMBEDDING_DIM/NUM_HEADS], fp2 (*vs)[EMBEDDING_DIM], int *seq, int *emb, int n, int d, int t, int factor)
{

	fp1 V = 0.0, sh = 0.0, sh1 = 0.0, sh2 = 0.0, sh3 = 0.0, sh4 = 0.0;
	fp1 s[SEQ_LEN][EMBEDDING_DIM/NUM_HEADS];

    Score: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col5:for (int l = 0; l < EMBEDDING_DIM/NUM_HEADS; l++) //(EMBEDDING_DIM/NUM_HEADS)
				  {
					  if(l<(d/(t*factor)))
					  {
						  sh = 0.0; sh1 = 0.0; sh2 = 0.0; sh3 = 0.0; sh4 = 0.0;

						  row5_1:for (int m = 0; m < (EMBEDDING_DIM/NUM_HEADS/4); m++)
						  {
							  if(m<(d/(t*4*factor)))
							  {
								  sh1 = sh1 + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }

						  row5_2:for (int m = (EMBEDDING_DIM/NUM_HEADS/4); m < (2*EMBEDDING_DIM/NUM_HEADS/4); m++)
						  {
							  if(m<(d/(t*4*factor)))
							  {
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }

						  row5_3:for (int m = (2*EMBEDDING_DIM/NUM_HEADS/4); m < (3*EMBEDDING_DIM/NUM_HEADS/4); m++)
						  {
							  if(m<(d/(t*4*factor)))
							  {
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }

						  row5_4:for (int m = (3*EMBEDDING_DIM/NUM_HEADS/4); m < (4*EMBEDDING_DIM/NUM_HEADS/4); m++)
						  {
							  if(m<(d/(t*4*factor)))
							  {
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  ////s[h][l] = sh/sqrtf(EMBEDDING_DIM/NUM_HEADS);
						  sh = sh1 + sh2 + sh3 + sh4;
						  s[h][l] = sh/(hls::sqrt(EMBEDDING_DIM/NUM_HEADS));
						  //cout << "s[h][l] = sh/sqrtf(EMBEDDING_DIM/NUM_HEADS) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*EMBEDDING_DIM/NUM_HEADS);

  softmax(s, n, d, t);

  int sequence = *seq;
  int embedding = *emb;

  VS: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  embedding = *emb;
			  row6:for (int r = 0; r < EMBEDDING_DIM/NUM_HEADS; r++)
			  {
				  V = 0.0;
				  if(r<(d/(t*factor)))
				  {
					  col6:for (int q = 0; q < EMBEDDING_DIM/NUM_HEADS; q++)//SEQ_LEN
					  {
						  if(q<(d/(t*factor))) //d/(t*factor)
						  {
							  V = V + s[p][q] * vv[p][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[sequence][embedding] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*EMBEDDING_DIM/NUM_HEADS + q << "]:" << vs[p*EMBEDDING_DIM/NUM_HEADS + q] << "\n";

			  }
			  sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }

  	  sequence = 0;
  	  *seq = sequence;
  	  *emb = embedding;

};
