#include "loadBq.h"
#include "TNN_5_2.h"

void loadBq1(fp2 *bq1,  fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{

			query_bias1:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq1[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq2(fp2 *bq2, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias2:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq2[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq3(fp2 *bq3, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias3:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq3[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq4(fp2 *bq4, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias4:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq4[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq5(fp2 *bq5, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias5:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq5[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq6(fp2 *bq6, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias6:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq6[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq7(fp2 *bq7, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias7:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq7[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq8(fp2 *bq8, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias8:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq8[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq9(fp2 *bq9, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias9:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq9[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq10(fp2 *bq10, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias10:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq10[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq11(fp2 *bq11, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias11:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq11[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}
}

void loadBq12(fp2 *bq12, fp2 *bias_stream, int *index2, int nheads_out, int embed_out, int factor)
{
			query_bias12:for(int j=0;j<fact1;j++)
			{
				if(j<factor)//(embed_out/(nheads_out*factor)))
				{
					//bq[l][i][j] = bias_stream[index2];// = query_bias0[j];
					bq12[j] = bias_stream[*index2];// = query_bias0[j];
					//cout<<"bq[" << i << ',' << j << "]=  " << bq[i][j]<< "\n";
					//cout<<"index2=  " << (*index2) << "\n";
					(*index2) = (*index2)+1;
				}
				else
					break;
			}


};
