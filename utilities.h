#ifdef __WAND__
target[name[utilities.h] type[include]]
#endif

#ifndef SYNTHMOD_VOICE_H
#define SYNTHMOD_VOICE_H

#include <cmath>

namespace Synthmod
	{
	inline float keyToFrequency(int key,float f_s)
		{
		return 440.0f*pow(2.0f,(key-69)/12.0f)/f_s;
		}

	inline float keyToFrequency(float key,float f_s)
		{
		return 440.0f*pow(2.0f,(key-69.0f)/12.0f)/f_s;
		}
	
	inline float frequencyToKey(float f)
		{
		return 12.0f*log(f/440.0f)/log(2.0f) + 69.0f;
		}
	}

#endif
