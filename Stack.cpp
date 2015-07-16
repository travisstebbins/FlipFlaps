#include "Stack.h"

//creates the stack of pancakes from 1 to the size of the stack
//and then shuffles the stack
void Stack::create_stack(int num_pancakes)
{
	for (int i = 1; i <= num_pancakes; ++i)
	{
		Pancake p{i};
		add(p);
	}
	unsigned seed = time(NULL);
	if(num_pancakes != 2)
		shuffle(stack.begin(), stack.end(), std::default_random_engine(seed));
}

//adds a pancake to the stack
void Stack::add(Pancake p)
{
	stack.push_back(p);
}

//flips the stack from the selected pancake to the top
//using iterators moving up and down the stack which
//swap the pancakes until the iterators are at the same place
void Stack::flip(int n)
{
	if(n > stack.size())
		error("flip size greater than number of pancakes");
	else
	{
		int d = stack.size() - 1;
		for (int u = n; u < stack.size(); ++u)
		{
			if (d <= u)
				return;
			else
			{
				Pancake temp = stack[d];
				stack[d] = stack[u];
				stack[u] = temp;
				--d;
			}
		}
	}
}

//function that prints the stack to the console (not used in the game)
void Stack::print_stack()
{
	for (int i = stack.size() - 1; i >= 0; --i)
		cout << stack[i].get_width() << '\n';
}

//function used to make sure the pancakes aren't already in order
//(not used in the game)
bool Stack::is_repeat(int w)
{
	for (int i = 0; i < stack.size(); ++i)
	{
		if (stack[i].get_width() == w)
			return true;
	}
	return false;
}

//returns the size of the stack
int Stack::size()
{
	return stack.size();
}

//returns a specific pancake in the stack
Pancake Stack::get(int n)
{
	return stack[n];
}

//returns the entires Stack object
vector<Pancake> Stack::get_stack()
{
	return stack;
}