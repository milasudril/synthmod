#ifdef __WAND__
target[name[filter_adsr_linear.h] type[include]]
#endif

#ifndef SYNTHMOD_FILTERADSRLINEAR_H
#define SYNTHMOD_FILTERADSRLINEAR_H

#include <cmath>

namespace Synthmod
	{
	class FilterAdsrLinear
		{
		public:
			enum class State:int
				{
				 ATTACK
				,DECAY
				,SUSTAIN
				,RELEASE
				};
			
			FilterAdsrLinear():A(1.0f),D(1.0f),S(0.75),R(1.0f)
				,state(State::RELEASE){}
				
			void attack()
				{state=State::ATTACK;}

			void release()
				{state=State::RELEASE;}
			
			State stateGet() const
				{return state;}

			float operator()(float value)
				{
				switch(state)
					{
					case State::ATTACK:
						value+=1.0f/A;
						if(value >= 1.0f)
							{state=State::DECAY;}
						return value;
					case State::DECAY:
						value+=(S-1.0f)/D; 
						if(value<=S)
							{state=State::SUSTAIN;}
						return value;
					case State::SUSTAIN:
						return S;
					case State::RELEASE:
						if(value<=0.0f)
							{return 0.0f;}
						value+=(-S)/R;
						return value;
					}
				return 0.0f;
				}
				
			float A;
			float D;
			float S;
			float R;
		
		private:
			State state;
		};
	}

#endif