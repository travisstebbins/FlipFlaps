//Travis Stebbins
//CSCE 121-505
//Scores_window.cpp

#include "Scores_window.h"

using namespace Graph_lib;

//constructor
	Scores_window::Scores_window(Point xy, int w, int h, const string& title)
		:Window{xy,w,h,title}
	{
		title_label = new Text{Point{(win_width/2)-35, win_height/15}, "Scores"};
		title_label->set_font_size(30);
		initials_input = new In_box{Point{win_width/2, win_height/7}, 200, 50, "Initials"};
		scores_file.open(scores_filename, ifstream::in);
		if (!scores_file) 
			error("can't open input file ",scores_filename);
		scores = get_scores(scores_file);
		scores_file.close();
		attach(*title_label);
		attach(*initials_input);
		display_scores(scores);
	}

//functions
	//public function that returns the player's initials entered
	//in the In_box; if the player enters more than 3 characters,
	//only the first 3 are used
	string Scores_window::get_initials()
	{	
		initials = initials_input->get_string();
		if (initials.length() > 3)
			initials = initials.substr(0,3);
		return initials;
	}

	//inputs the scores from scores.txt
	vector<string> Scores_window::get_scores(ifstream& scores_file)
	{
		vector<string> tmp;
		string name;
		string score;
		while(scores_file >> name >> score)
		{
			string s = name + '\t' + score;
			tmp.push_back(s);
		}
		return tmp;
	}

	//displays the initials and scores to the screen
	void Scores_window::display_scores(vector<string> scores)
	{
		int y = 225;
		for (int i = 0; i < scores.size(); ++i)
		{
			Text* t = new Text{Point{(win_width/2)-35, y}, to_string(i + 1) + ") " + scores[i]};
			t->set_font_size(20);
			attach(*t);
			y += 50;
		}
	}