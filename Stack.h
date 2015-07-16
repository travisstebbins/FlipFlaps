#include "Pancake.h"

class Stack
{
	vector<Pancake> stack;
	public:
		void create_stack(int num_pancakes);
		void add(Pancake p);
		void flip(int n);
		void print_stack();
		bool is_repeat(int n);
		int size();
		Pancake get(int n);
		vector<Pancake> get_stack();
};