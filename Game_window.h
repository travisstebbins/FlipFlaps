//Travis Stebbins
//CSCE 121-505
//Game_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Stack.h"
#include "game.h"
#include "find_solution.h"

using namespace Graph_lib;

struct Game_window : Graph_lib::Window
{
	//constructor
		Game_window(Point xy, int w, int h, const string& title, int stack_size);
	//objects
		Rectangle* clear;
	//functions
		int get_score();
	private:
		//objects
			Stack stack;
			Vector_ref<Button> flip_buttons;
			int flip_counter;
			Text* flip_counter_label;
			int min_moves;
			Text* min_moves_label;
			int score;
			Text* score_label;
		//constants
			const int pancake_height{30};
			const int button_width{50};
			const int button_height{pancake_height};
			const int win_width{600};
			const int win_height{500};
			const int x_pad{15};
			const int y_pad{50};
			const int pancake_pad{10};
		//functions
			void cb_flip(int n);
			void redraw_game_screen();
			bool is_solved();
			int calc_min_moves();
			vector<int> reverse(vector<Pancake> in);
			int calc_score();
};