//Sam Stegall
//CSCE 121-505
//Result_window.h

#include "Result_window.h"

using namespace Graph_lib;

//constructor
        Result_window::Result_window(Point xy, int w, int h, const string& title)
                :Window{xy,w,h,title}
        {
                //create GUI
                        title_label = new Text{Point{(win_width/2)-35, win_height/15}, "Results"};
                        title_label->set_font_size(30);
                        attach(*title_label);
                //obtain initials and scores
                        input_scores();
        }

//functions
		//sets the player's initials
		void Result_window::set_initials(string inits)
		{
			initials = inits;
		}
		//sets the player's score
		void Result_window::set_player_score(int p_score)
		{
			player_score = p_score;
		}
		//called in game.cpp to update the data and screen after the player's data has been acquired
		void Result_window::update()
		{
			sort_scores();
			display_scores();
			output_scores();
		}
		//displays the vectors of initials and scores on the screen; the player's score is bolded
        void Result_window::display_scores()
        {
                int y = 150;
                for (int i = 0; i < initials_vector.size(); ++i)
                {
                        Text* t = new Text{Point{(win_width/2)-35, y}, to_string(i+1) + ") " + initials_vector[i] + '\t' + to_string(scores_vector[i])};
                        t->set_font_size(20);
                        if(initials_vector[i] == initials && scores_vector[i] == player_score)
                                t->set_font(FL_HELVETICA_BOLD);
                        attach(*t);
                        y += 50;
                }
        }
		//inputs the scores from scores.txt
        void Result_window::input_scores()
        {
				scores_in.open(scores_filename, ifstream::in);
                if (!scores_in)
					error("can't open input file ",scores_filename);
                string initials;
                int score;
                while(scores_in >> initials >> score)
                {
                        initials_vector.push_back(initials);
                        scores_vector.push_back(score);
                }
				scores_in.close();
        }
		//sorts the player's score into the list of high scores
        void Result_window::sort_scores()
        {
                initials_vector.push_back(initials);
                scores_vector.push_back(player_score);
                for(int i=0; i < scores_vector.size() - 1; ++i)
                {
                        for(int j=i; j < scores_vector.size() - i - 1; ++j)
                        {
                                if(scores_vector[j] < scores_vector[j+1])
                                {
                                        int tmpi = scores_vector[j];
                                        scores_vector[j] = scores_vector[j+1];
                                        scores_vector[j+1] = tmpi;
                                        string tmps = initials_vector[j];
                                        initials_vector[j] = initials_vector[j+1];
                                        initials_vector[j+1] = tmps;
                                }
                        }
                }
        }
		//outputs the top 5 scores into scores.txt
		void Result_window::output_scores()
		{
			scores_out.open(scores_filename, std::ofstream::out);
			if (!scores_out)
					error("can't open output file ",scores_filename);
			int stack_size = 5;
			if(initials_vector.size() < 5)
				stack_size = initials_vector.size();
			for(int i = 0; i < stack_size; ++i)
			{
				scores_out << initials_vector[i] + " " + to_string(scores_vector[i]) + '\n';
			}
			scores_out.close();
		}