#include "std_lib_facilities_4.h"

class Pancake
{
	int w;
	
	//constructors
	public:
		Pancake(int ww)
		{
			w = {ww};
		}
		void set_width(int ww)
		{
			w = ww;
		}
		int get_width()
		{
			return w;
		}
};