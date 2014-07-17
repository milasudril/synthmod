#ifdef __WAND__
target[name[filter_adsr.h] type[include]]
#endif

#ifndef SYNTHMOD_FILTERADSR_H
#define SYNTHMOD_FILTERADSR_H

#include <cmath>

namespace Synthmod
	{
	class FilterAdsr
		{
		public:
			enum class State:int
				{
				 ATTACK
				,DECAY
				,SUSTAIN
				,RELEASE
				};
			
			FilterAdsr():A(1.0f),D(1.0f),S(0.75),R(1.0f),state(State::RELEASE){}
				
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
						value+=(1.0f - value)/A;
						if(std::abs(1.0f - value) < threshold)
							{state=State::DECAY;}
						return value;
					case State::DECAY:
						value+=(S-value)/D; 
						if(std::abs(S - value) < threshold)
							{state=State::SUSTAIN;}
						return value;
					case State::SUSTAIN:
						return S;
					case State::RELEASE:
						value+=(-value)/R;
						return value;
					}
				return 0.0f;
				}
				
			float A;
			float D;
			float S;
			float R;
		
		private:
			static constexpr const float threshold=1.0f/1024;
			
			State state;
		};
	}

#endif