//Travis Stebbins
//CSCE 121-505
//Difficulty_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"
#include "game.h"

using namespace Graph_lib;

struct Difficulty_window : Graph_lib::Window
{
	//constructor
		Difficulty_window(Point xy, int w, int h, const string& title);
	//functions
		int get_difficulty();
	private:
		//objects
			Text* title_label;
			Button* b2;
			Button* b3;
			Button* b4;
			Button* b5;
			Button* b6;
			Button* b7;
			Button* b8;
			Button* b9;
			int difficulty;
		//constants
			const int win_width{600};
			const int win_height{500};
		//functions
			void set_difficulty(int n);
};