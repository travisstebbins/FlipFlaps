//Sam Stegall
//CSCE 121-505
//Instructions_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Instructions_window : Graph_lib::Window
{
	//constructor
		Instructions_window(Point xy, int w, int h, const string& title);
	//functions
	private:
		Point* win_top_left = new Point{100,100};
		Point* top_bullet = new Point{25,100};
		Point* middle_bullet = new Point{25,210};
		Point* lower_bullet = new Point{25,320};
		
		Text* title_label;
		Text* top_text;
		Text* top_text2;
		Text* middle_text;
		Text* middle_text2;
		Text* lower_text;
		Text* lower_text2;
		
		int size = 15;
};

Instructions_window::Instructions_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title}
{
	title_label = new Text{Point{210,50}, "Instructions"};
	title_label->set_font_size(30);
	top_text = new Text{*top_bullet,"1) The goal is to arrange the pancakes with"};
	top_text->set_font_size(size);
	top_text2 = new Text{Point{75, 150}, "the smallest on top and largest on bottom."};
	top_text2->set_font_size(size);
	middle_text = new Text{*middle_bullet,"2) You can insert between any two pancakes and"};
	middle_text->set_font_size(size);
	middle_text2 = new Text{Point{75, 260}, "flip the order above the insertion."};
	middle_text2->set_font_size(size);
	lower_text = new Text{*lower_bullet,"3) The game is over when the pancakes are ordered, or if"};
	lower_text->set_font_size(size);
	lower_text2 = new Text{Point{75, 370}, "your score falls below 0 by using too many moves."};
	lower_text2->set_font_size(size);
	attach(*title_label);
	attach(*top_text);
	attach(*top_text2);
	attach(*middle_text);
	attach(*middle_text2);
	attach(*lower_text);
	attach(*lower_text2);
}