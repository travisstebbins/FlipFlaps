//Travis Stebbins
//CSCE 121-505
//Game.cpp

#include "Splash_window.h"
#include "Instructions_window.h"
#include "Scores_window.h"
#include "Difficulty_window.h"
#include "Game_window.h"
#include "Result_window.h"
#include "game.h"

using namespace Graph_lib;

//variables
	string initials;	
	int* difficulty;
	int score;

//GUI objects
	Splash_window* splash_win;
	Instructions_window* instructions_win;
	Scores_window* scores_win;
	Difficulty_window* difficulty_win;
	Game_window* game_win;
	Result_window* result_win;
	
	Button* splash_win_button;
	Button* instructions_win_button;
	Button* scores_win_button;
	Button* result_win_button;
	
//functions
	void cb_splash_win_button();
	void cb_scores_win_button();
	void cb_game_win_button();
	void cb_instructions_window_button();
	void cb_result_win_button();

int main()
{
	try
	{
		//create windows
		splash_win = new Splash_window{Point{100,100}, 600, 500, "FlipFlap"};
		instructions_win = new Instructions_window{Point{100,100}, 600, 500, "FlipFlap"};
		scores_win = new Scores_window{Point{100,100}, 600, 500, "FlipFlap"};
		difficulty_win = new Difficulty_window{Point{100,100}, 600, 500, "FlipFlap"};
		result_win = new Result_window{Point{100,100}, 600, 500, "FlipFlap"};;
		//hide all windows except splash screen
		instructions_win->hide();
		scores_win->hide();
		difficulty_win->hide();
		result_win->hide();
		//add "Next" buttons and attach
		splash_win_button = new Button{Point{540,460},50,30,"Next",Callback(cb_splash_win_button)};	
		instructions_win_button = new Button{Point{540, 460}, 50, 30, "Next", Callback(cb_instructions_window_button)};
		scores_win_button = new Button{Point{540,460},50,30,"Next",Callback(cb_scores_win_button)};
		result_win_button = new Button{Point{540,460},50,30,"Quit", Callback(cb_result_win_button)};
		splash_win->attach(*splash_win_button);
		instructions_win->attach(*instructions_win_button);
		scores_win->attach(*scores_win_button);
		result_win->attach(*result_win_button);
	
		return gui_main();
	}
	catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
	}
	catch (...) {
			cerr << "Some exception\n";
			return 2;
	}
	
}

//"next" button functions
void cb_splash_win_button()
{
	splash_win->hide();
	instructions_win->show();
}

void cb_instructions_window_button()
{
	instructions_win->hide();
	scores_win->show();
}

void cb_scores_win_button()
{
	scores_win->hide();
	initials = scores_win->get_initials();
	if(initials == "")
		initials = "???";
	difficulty_win->show();
}

void difficulty_window_next()
{
	difficulty = new int(difficulty_win->get_difficulty());
	difficulty_win->hide();
	game_win = new Game_window{Point{100,100}, 600, 500, "FlipFlap", *difficulty};
}

void end_game()
{
	game_win->hide();
	score = game_win->get_score();
	result_win->set_initials(initials);
	result_win->set_player_score(score);
	result_win->update();
	result_win->show();
}

void cb_result_win_button()
{
	result_win->hide();
}