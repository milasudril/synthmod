#ifdef __WAND__
target[name[oscillator.h] type[include]]
#endif

#ifndef SYNTHMOD_OSCILLATOR_H
#define SYNTHMOD_OSCILLATOR_H

#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace Synthmod
	{
	class Oscillator
		{
		public:
		//	Oscillator()=default;
			Oscillator(const Oscillator&)=default;
			Oscillator(Oscillator&&)=default;
			Oscillator& operator=(const Oscillator&)=default;
			Oscillator& operator=(Oscillator&&)=default;

			
			Oscillator(const float* waveform,size_t n_frames):
				m_waveform(waveform),length(n_frames),phi(0),f(0.25)
				{}
				
			float operator()()
				{
				size_t i = (size_t)phi;
				phi += length*f;

				if(phi >= length)
					{phi -= length;}

				return m_waveform[i];
				}
			
			void frequencySet(float f_new)
				{f=f_new;}
			
			void phaseSet(uint32_t phase)
				{
				phi=phase%( (uint32_t)length);
				}
			
			void phaseSet(size_t N,float phi_0)
				{
				auto temp=N*f + phi_0;
				phi=(temp-int(temp))*length;
				}
				
			void dump() const
				{
				int L=length;
				for(int k=0;k<L;++k)
					{printf("%d  %.7f\n",k,m_waveform[k]); }
				}
			
		private:
			const float* m_waveform;
			float length;
			float phi;
			float f;
		};

	}

#endif
