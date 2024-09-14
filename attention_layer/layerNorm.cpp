#include "layerNorm.h"
#include "TNN_5_2.h"


void layerNorm(fp1 (*x)[EMBEDDING_DIM], fp3 (*out)[EMBEDDING_DIM], fp2* gamma, fp2* beta, fp1 *eps, int seq, int embed)
{

	fp1 m[SEQ_LEN]; //= {0.0};
	fp1 v[SEQ_LEN]; //= {0.0};

    mean_out:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		mean_in:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				m[i] += x[i][j];
    			}
    			else
    				break;
    		}
    		m[i] /= fp1(embed);
    		//printf("m[%d] = %f\n", i, m[i]);
    		//cout << "m[i]= " << m[i] << "\n";
    	}
    	else
    		break;

    }


    variance_out:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		variance_in:for (int j = 0; j < EMBEDDING_DIM; j++)
            {
    			if(j<embed)
    			{
    				v[i] += (x[i][j]-m[i])*(x[i][j]-m[i]);
    			}
    			else
    				break;
            }
            v[i] /= fp1(embed);
            //cout << "v[i]= " << v[i] << "\n";
    	}
    	else
    		break;
            //
    }


    norm_out1:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		norm_in1:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				//cout << "eps = " << hls::sqrt(*eps) <<"\n";
    				float d = hls::sqrt(v[i] + *eps);//fp1(hls::sqrt(v[i] + *eps));
    				float e = x[i][j] - m[i];
    				//cout << "e = " << e << "\n";
    				//cout << "d = " << d << "\n";
    				out[i][j] = e/d;//hls::divide(e,d);///hls::sqrt(v[i] + *eps);
    				//cout << "out[i][j] = " << out[i][j] <<"\n";

    			}
    			else
    				break;
    		}
    	}
    	else
    		break;
    }

    // Normalize input using mean and variance
    norm_out2:for (int i = 0; i < SEQ_LEN; i++)
    {
    	if(i<seq)
    	{
    		norm_in2:for (int j = 0; j < EMBEDDING_DIM; j++)
    		{
    			if(j<embed)
    			{
    				out[i][j]= gamma[j] * out[i][j] + beta[j];
 //   				printf("gamma[%d]: %f \n", j, gamma[j]);
 //   				printf("beta[%d]: %f \n", j, beta[j]);
 //   				printf("second_out[%d][%d]: %f \n", i, j, out[i][j]);
    			}
    			else
    				break;
            }

    	}
    	else
    		break;
    }


};

