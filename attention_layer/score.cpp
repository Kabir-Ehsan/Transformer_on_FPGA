#include "score.h"
#include "softmax.h"
#include "TNN_5_2.h"

//void attention_score(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int *seq, int *emb, int n, int d, int t, int factor, int factorsqrt)
void attention_score(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col5:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row5:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + qq[h][m] * kk[l][m];//sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row6:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col6:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score2(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score2: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col52:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row52:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + qq[h][m] * kk[l][m];//sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS2: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row62:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col62:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score3(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score3: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col53:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row53:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + qq[h][m] * kk[l][m];//sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS3: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row63:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col63:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score4(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score4: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col54:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row54:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  //sh = sh + sh_temp;
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS4: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row64:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col64:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score5(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score5: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col55:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row55:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  //sh = sh + sh_temp;

								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS5: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row65:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col65:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score6(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score6: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col56:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row56:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  //sh = sh + sh_temp;
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS6: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row66:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col66:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score7(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score7: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col57:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row57:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  //sh = sh + sh_temp;
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS7: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row67:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col67:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score8(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score8: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col58:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row58:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  //sh_temp = qq[h][m] * kk[l][m];
								  //sh = sh + sh_temp;
								  sh = sh + qq[h][m] * kk[l][m];
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS8: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row68:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col68:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  //V_temp = s[p][q] * vv[q][r];
							  //V = V + V_temp;
							  V = V + s[p][q] * vv[q][r];
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score9(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score9: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col59:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row59:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS9: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row69:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col69:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  V_temp = s[p][q] * vv[q][r];
							  V = V + V_temp;
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score10(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score10: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col510:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row510:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS10: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row610:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col610:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  V_temp = s[p][q] * vv[q][r];
							  V = V + V_temp;
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score11(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score11: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col511:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row511:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS11: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row611:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col611:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  V_temp = s[p][q] * vv[q][r];
							  V = V + V_temp;
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};

void attention_score12(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 (*vs)[fact1], int n, int d, int t, int factor, int factorsqrt)
{

	fp1 V = 0.0, sh = 0.0;
	fp1 V_temp = 0.0, sh_temp = 0.0;
	fp1 s[SEQ_LEN][SEQ_LEN] = {0};//fact1];

    Score12: for(int h=0; h < SEQ_LEN; h++) //NUM_HEADS
  	  	 {
	  	  	  if(h<n)
	  	  	  {
				  col512:for (int l = 0; l < SEQ_LEN; l++) //(fact1)
				  {
					  if(l<n)//(d/(t*factor)))
					  {
						  sh = 0.0;
						  row512:for (int m = 0; m < fact1; m++)
						  {
							  if(m<factor)//(d/(t*factor)))
							  {
								  sh_temp = qq[h][m] * kk[l][m];
								  sh = sh + sh_temp;
							  }
							  else
								  break;
						  }
						  //cout << "sh [" <<h <<',' <<l << "]: " << sh << "\n";
						  s[h][l] = sh/factorsqrt;//hls::sqrt(factor);//d/t);//softmax(sh/sqrtf(EMBEDDING_DIM), 1); //h*SEQ_LEN+l]
						  //cout << "s[h][l] = sh/sqrtf(fact1) [" <<h <<',' <<l << "]: " << s[h][l] << "\n";
					  }
					  else
						  break;
				  }
	  	  	  }
	  	  	  else
	  	  		  break;
  	  	 }

  //softmax(s, SEQ_LEN*fact1);

  softmax(s, n, d, t);


  VS12: for(int p=0; p<SEQ_LEN; p++)
 	 {
	  	  if(p<n)
	  	  {
	  		  //embedding = *emb;
			  row612:for (int r = 0; r < fact1; r++)//SEQ_LEN
			  {
				  V = 0.0;
				  if(r<factor)//(d/(t*factor)))
				  {
					  col612:for (int q = 0; q < SEQ_LEN; q++)// fact1
					  {
						  if(q<n)//(d/(t*factor))) //d/(t*factor)
						  {
							  V_temp = s[p][q] * vv[q][r];
							  V = V + V_temp;
							  //cout << "s = [" <<p <<',' <<r << "]: " << s[p][r] << "\n";
							  //cout << "vv = [" <<q <<',' <<r << "]: " << vv[q][r] << "\n";
							  //cout << "V:" << V << "\n";
						  }
						  else
							  break;
					  }
					  vs[p][r] = V;
					  //cout << "vs[" << sequence << "][" << embedding << "]:" << vs[sequence][embedding]  << "\n";
					  //embedding = embedding+1;

				  }
				  else
					  break;
//		  		  cout << "vs[" << p*fact1 + q << "]:" << vs[p*fact1 + q] << "\n";

			  }
			  //sequence = sequence+1;

	  	  }
	  	  else
	  		  break;
 	 }
};
