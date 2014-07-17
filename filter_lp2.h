#ifdef __WAND__
target[name[filter_lp2.h]type[include]]
#endif

#ifndef SYNTHMOD_FILTERLP2_H
#define SYNTHMOD_FILTERLP2_H

#include <vector/vector2d.h>

#include <cstdio>

namespace Synthmod
	{
	class FilterLp2
		{
		public:
			FilterLp2():r{0,0},f_old{0,0}
				{}
			
			void dtSet(double dt_new)
				{dt=dt_new;}
			
			void frequencySet(double omega_c_new)
				{
				omega_c=omega_c_new;
				update();
				}
			
			void qualitySet(double Q_new)
				{
				Q=Q_new;
				update();
				}				
			
			float operator()(float value)
				{
				Vector::Matrix22<double> I=
					{
					 1.0 , 0.0
					,0.0 , 1.0
					};
				
				Vector::Vector2d<double> f{0.0,omega_0*omega_0*value};

				r=( r + 0.5*dt*(f + f_old + A*r) )/(I - 0.5*dt*A);

				f_old=f;
				return r.x;
				}
				
		private:
			Vector::Matrix22<double> A;
			Vector::Vector2d<double> r;
			Vector::Vector2d<double> f_old;
			double omega_0;
			double dt;
			double omega_c;
			double Q;
			
			void update()
				{
				omega_0=2*Q*omega_c/sqrt(4*Q*Q - 1);
				
				A=
					{
					 0.0              , 1.0f
					,-omega_0*omega_0 , -omega_0/Q
					};
				}
			
		};
	}

#endif
