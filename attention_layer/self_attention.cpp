#include "self_attention.h"
#include "TNN_5_2.h"

void self_attention1(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV1: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col41:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row41:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k]; // d/t
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k]; // d/t
							  //sv = sv + x[i*tile+j] * wv[j*factor+k]; // d/t

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
/*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention2(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV2: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col42:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row42:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
/*

							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention3(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV3: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col43:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row43:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
/*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention4(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV4: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col44:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row44:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
/*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention5(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV5: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col45:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row45:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
							  /*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention6(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV6: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col46:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row46:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
/*							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention7(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV7: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col47:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row47:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
/*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;*/


							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention8(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;
	fp1 sq_temp  = 0.0, sk_temp = 0.0, sv_temp = 0.0;
  QKV8: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col48:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row48:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
/*
							  sq_temp = x[i*tile+j] * wq[k*factor+j];
							  sk_temp = x[i*tile+j] * wk[k*factor+j];
							  sv_temp = x[i*tile+j] * wv[k*factor+j];

							  sq = sq + sq_temp;
							  sk = sk + sk_temp;
							  sv = sv + sv_temp;
*/

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention9(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV9: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col49:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row49:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention10(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV10: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col410:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row410:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //cout << "sq: " << ":" << sq << "\n";
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention11(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV11: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col411:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row411:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  //cout << "x: " << i*8+j << ":" << x[i*8+j] << "\n";
							  //cout << "wq: " << j*d/t+k << ":" << wq[j*d/t+k] << "\n";
							  //sq = sq + x[i*tile+j] * wq[j*factor+k];
							  //sk = sk + x[i*tile+j] * wk[j*factor+k];
							  //sv = sv + x[i*tile+j] * wv[j*factor+k];

							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  //cout << "bq : " << k << ":" << bq[k] << "\n";
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];

				//	  cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				//	  cout << "kk[" << i << "," << k << "]: " << kk[i][k] << "\n";
				//	  cout << "vv[" << i << "," << k << "]: " << vv[i][k] << "\n";
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention12(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV12: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col412:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row412:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention13(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV13: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col413:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row413:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention14(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV14: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col414:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row414:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention15(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV15: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col415:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row415:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention16(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV16: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col416:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row416:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention17(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV17: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col417:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row417:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention18(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV18: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col418:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row418:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention19(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV19: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col419:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row419:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}

void self_attention20(fp1* x, fp2* wq, fp2* wk, fp2* wv, fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], int n, int d, int t,  int tile, int factor)
{
	//cout<< "self attention start" << '\n';
	fp1 sq  = 0.0, sk = 0.0, sv = 0.0;

  QKV20: for (int i = 0; i < SEQ_LEN; i++)
  	   {
	  	  if(i<n)
	  	  {
			  col420:for(int k = 0; k < (fact1); k++)
			  {
				  if(k<factor)//(d/(t)))//*factor
				  {
					  sq = 0.0;
					  sk = 0.0;
					  sv = 0.0;
					  row420:for (int j = 0; j < (TILE_SIZE); j++) // EMBEDDING_DIM
					  {
						  if(j<(tile))//d/factor))
						  {
							  sq = sq + x[i*tile+j] * wq[k*factor+j];
							  sk = sk + x[i*tile+j] * wk[k*factor+j];
							  sv = sv + x[i*tile+j] * wv[k*factor+j];
						  }
						  else
							  break;
					  }
					  qq[i][k] = qq[i][k]+sq;//+bq[k];
					  kk[i][k] = kk[i][k]+sk;//+bk[k];
					  vv[i][k] = vv[i][k]+sv;//+bv[k];
				  }
				  else
					  break;
			  }
	  	  }
	  	  else
	  		  break;
  	   }
}
