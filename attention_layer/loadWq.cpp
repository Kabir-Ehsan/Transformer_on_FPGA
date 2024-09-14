#include "loadWq.h"
#include "TNN_5_2.h"

void loadWq1(fp2 *wq1_1, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int tile, int factor)
{
	//headq1:for(int j=0;j<NUM_HEADS;j++)
	//{
	//	if(j<(nheads_out))
	//	{
			weightQ1_1:for(int i=0;i<wfact;i++)  //TILE_SIZE*EMBEDDING_DIM/(NUM_HEADS)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_1[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << i << "]=  " << wq1_1[i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq2(fp2 *wq1_2, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int tile, int factor)
{
			weightQ1_2:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_2[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq3(fp2 *wq1_3, fp2 *weight_stream1, int *index, int nheads_out, int embed_out, int tile, int factor)
{
			weightQ1_3:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_3[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq4(fp2 *wq1_4, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_4:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_4[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq5(fp2 *wq1_5, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_5:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_5[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq6(fp2 *wq1_6, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_6:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_6[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq7(fp2 *wq1_7, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_7:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_7[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq8(fp2 *wq1_8, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_8:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_8[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq9(fp2 *wq1_9, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_9:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_9[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq10(fp2 *wq1_10, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_10:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_10[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq11(fp2 *wq1_11, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_11:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_11[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
}

void loadWq12(fp2 *wq1_12, fp2 *weight_stream1, int *index, int nheads_out, int embed_out,  int tile, int factor)
{
			weightQ1_12:for(int i=0;i<wfact;i++)
			{
				if(i<factor)//((tile)*(embed_out))/(nheads_out*factor))
				{
					//wq1_1[l][j][i] = weight_stream1[index];
					wq1_12[i] = weight_stream1[*index];
					//cout<<"wq1_1[" << j << ',' << i << "]=  " << wq1_1[j][i]<< "\n";
					(*index)++;

				}
				else
					break;
			}
	//	}
	//	else
	//		break;
	//}
};
