//Sam Stegall
//CSCE 121-505
//Result_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Result_window : Graph_lib::Window
{
	//constructor
		Result_window(Point xy, int w, int h, const string& title);
	//functions
		void set_initials(string inits);
		void set_player_score(int p_score);
		void update();
	private:
		//objects
			Text* title_label;
			string initials;
			ifstream scores_in;
			ofstream scores_out;
			vector<string> initials_vector;
			vector<int> scores_vector;
			int player_score;
		//constants		
			const int button_width{50};
			const int button_height{30};
			const int win_width{600};
			const int win_height{500};
			const string scores_filename{"scores.txt"};
		//functions
			void display_scores();
			void input_scores();
			void sort_scores();
			void output_scores();
};