#ifdef __WAND__
target[name[synthmod_lp2test] type[application]]
#endif

#include "filter_lp2.h"
#include <mathext/constants.h>
#include <cstdio>

int main()
	{
	Synthmod::FilterLp2 filter;

/*	Vector::Matrix22<float> A={1,2,3,4};
	Vector::Vector2d<float> y={1,2};
	auto x=y/A;
	printf("%.7g %.7g\n",x.x,x.y);
	auto y_test=A*x;
	printf("%.7g %.7g\n",y_test.x,y_test.y);*/
	
	filter.qualitySet(2.0f);
	filter.frequencySet(2*MathExt::PI*440);
	filter.dtSet(1.0f/48000.0f);
	
	size_t k=0;
	for(k=0;k<16;++k)
		{
		printf("%.7g\n",filter(1));
		}
	
	}
