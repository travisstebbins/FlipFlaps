//Travis Stebbins
//CSCE 121-505
//Difficulty_window.cpp

#include "Difficulty_window.h"

using namespace Graph_lib;

//constructor
        Difficulty_window::Difficulty_window(Point xy, int w, int h, const string& title)
			:Window{xy,w,h,title}
        {
                //create GUI
                        title_label = new Text{Point{(win_width/2)-35, win_height/15}, "Difficulty"};
                        title_label->set_font_size(30);
                        attach(*title_label);
						b2 = new Button{Point{100,300},50,50,"2",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(2);}};
						b3 = new Button{Point{150,300},50,50,"3",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(3);}};
						b4 = new Button{Point{200,300},50,50,"4",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(4);}};
						b5 = new Button{Point{250,300},50,50,"5",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(5);}};
						b6 = new Button{Point{300,300},50,50,"6",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(6);}};
						b7 = new Button{Point{350,300},50,50,"7",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(7);}};
						b8 = new Button{Point{400,300},50,50,"8",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(8);}};
						b9 = new Button{Point{450,300},50,50,"9",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(9);}};
						attach(*b2);
						attach(*b3);
						attach(*b4);
						attach(*b5);
						attach(*b6);
						attach(*b7);
						attach(*b8);
						attach(*b9);
        }

//functions
		//called by the button that is pushed to set the difficutly level
		void Difficulty_window::set_difficulty(int n)
		{
			difficulty = n;
			difficulty_window_next();
		}
		//used by game.cpp to acquire the difficulty level for the rest of the game
		int Difficulty_window::get_difficulty()
		{
			return difficulty;
		}