#include "activation.h"
#include "biasAdd.h"

//#include "TNN_5.h"
/*
template<class T, class U>
T sig(U x);

template<class T, class U>
T tan(U x);
*/

template<class T, class U>
T sig(U x)
{
	return 1/(1+exp(-x));
};

template<class T, class U>
T tan(U x)
{
	//return (exp(-2*x)-1)/(exp(-2*x)+1);
	return (1 - 2*sig<T,U>(-2*x));
};


void biasAdd(fp1 (*qq)[fact1],  fp1 (*kk)[fact1], fp1 (*vv)[fact1], fp2 *bq, fp2 *bk, fp2 *bv, int n, int d, int t, int factor)
{
	bias_loop1:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop2:for(int k = 0; k < fact1; k++) //(fact1)
			{
				if(k<factor)//(d/(t)))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					kk[i][k] = qq[i][k]+bk[k];
					vv[i][k] = qq[i][k]+bv[k];

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
};


void biasAdd2(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop3:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop4:for(int k = 0; k < (EMBEDDING_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};

void biasAdd3(fp3 (*qq)[HIDDEN_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop5:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop6:for(int k = 0; k < (HIDDEN_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					qq[i][k] = relu(qq[i][k]);//gelu(qq[i][k]);
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};

void biasAdd4(fp3 (*qq)[EMBEDDING_DIM], fp2 *bq, int n, int d)//, int t)
{
	bias_loop7:for (int i = 0; i < SEQ_LEN; i++)
	{
	  	if(i<n)
	  	{
			bias_loop8:for(int k = 0; k < (EMBEDDING_DIM); k++)
			{
				if(k<(d))//*factor
				{
				    //cout << "bq : " << k << ":" << bq[k] << "\n";
					qq[i][k] = qq[i][k]+bq[k];
					qq[i][k] = relu(qq[i][k]);;//tan<fp3, fp1>(qq[i][k]);
					//cout << "qq[" << i << "," << k << "]: " << qq[i][k] << "\n";
				}
				else
					break;
			}
		}
		else
			break;
  	}
};


