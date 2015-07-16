//Travis Stebbins
//CSCE 121-505
//Game_window.cpp

#include "Game_window.h"

using namespace Graph_lib;

//constructor
	Game_window::Game_window(Point xy, int w, int h, const string& title, int stack_size)
		:Window{xy,w,h,title}
	{
		//create stack and GUI
		stack.create_stack(stack_size);		
		min_moves = calc_min_moves();
		score = 0;
		Button* flip0 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*0)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(0);}};
		Button* flip1 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*1)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(1);}};
		Button* flip2 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*2)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(2);}};
		Button* flip3 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*3)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(3);}};
		Button* flip4 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*4)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(4);}};
		Button* flip5 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*5)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(5);}};
		Button* flip6 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*6)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(6);}};
		Button* flip7 = new Button{Point{x_pad,(win_height - y_pad) - ((button_height+10)*7)},button_width,button_height,"Flip",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(7);}};
		flip_buttons.push_back(flip0);
		flip_buttons.push_back(flip1);
		flip_buttons.push_back(flip2);
		flip_buttons.push_back(flip3);
		flip_buttons.push_back(flip4);
		flip_buttons.push_back(flip5);
		flip_buttons.push_back(flip6);
		flip_buttons.push_back(flip7);
		for(int i = 0; i < stack.size() - 1; ++i)
		{
			this->attach(flip_buttons[i]);
		}
		flip_counter = 0;
		flip_counter_label = new Text{Point{400,50}, "Moves: " + to_string(flip_counter)};
		min_moves_label = new Text{Point{400,25}, "Can be done in " + to_string(min_moves) + " moves"};
		score_label = new Text{Point{400,75}, "Score: " + to_string(score)};
		clear = new Rectangle{Point{button_width + x_pad,0},win_width,win_height};
		clear->set_color(Color::invisible);
		clear->set_fill_color(FL_BACKGROUND_COLOR);
		attach(*flip_counter_label);
		attach(*min_moves_label);
		redraw_game_screen();
	}

//functions
	//flip the pancakes
	void Game_window::cb_flip(int n)
	{
		stack.flip(n);
		++flip_counter;
		redraw_game_screen();
	}

	//redraw the pancakes on the screen
	void Game_window::redraw_game_screen()
	{
		flush();
		int y = win_height - y_pad;
		attach(*clear);
		for(int i=0;i<stack.size();++i)
		{
			int x = (win_width/2) - ((stack.get(i).get_width() * 50)/2);
			Rectangle* r = new Rectangle{Point{x,y},(stack.get(i).get_width() * 50),pancake_height};
			Color pancake_brown(fl_rgb_color(199,168,89));
			Color dark_pancake_brown(fl_rgb_color(146,106,0));
			r->set_color(dark_pancake_brown);
			r->set_fill_color(pancake_brown);
			attach(*r);
			y -= pancake_height + pancake_pad;
		}
		flip_counter_label->set_label("Moves: " + to_string(flip_counter));
		min_moves_label->set_label("Can be done in " + to_string(min_moves) + " moves");
		score = calc_score();
		score_label->set_label("Score: " + to_string(score));
		attach(*flip_counter_label);
		attach(*min_moves_label);
		attach(*score_label);		
		if(score < 0)
			end_game();
		if(is_solved())
			end_game();
	}

	//check if the game has been won
	bool Game_window::is_solved()
	{
		for(int i = 0; i < stack.size()-1; ++i)
		{
			if(stack.get(i).get_width() < stack.get(i+1).get_width())
				return false;
		}
		return true;
	}
	
	//calculate the minimum moves required to win
	int Game_window::calc_min_moves()
	{
		vector<int> reverse_stack = reverse(stack.get_stack());
		vector<int>* min_moves_vector = find_solution(reverse_stack);
		int min_moves = min_moves_vector->size();
		return min_moves;
	}

	//reverse the Stack vector of pancakes since Stack has the bottom pancake
	//at index 0 and find_solution() requires the top pancake at index 0
	vector<int> Game_window::reverse(vector<Pancake> in)
	{
		vector<int> out;
		for(int i=in.size() - 1; i >= 0; --i)
			out.push_back(in[i].get_width());
		return out;
	}
	
	//calculate the player's score
	int Game_window::calc_score()
	{
		int score = (100 - 10 * (flip_counter - min_moves)) * stack.size();
		return score;
	}
	
	int Game_window::get_score()
	{
		return score;
	}