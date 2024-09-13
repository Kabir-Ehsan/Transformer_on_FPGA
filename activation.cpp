#include "activation.h"
//#include "TNN_5.h"



fp3 relu(fp1 x)
{
  //return fmax(0, x);
	if(x<0)
		return 0;
	else
		return x;
};

fp3 gelu(fp1 x)
{
    return fp1(0.5) * x * (fp1(1.0) + hls::erf(x / hls::sqrt(fp1(2.0))));
};
