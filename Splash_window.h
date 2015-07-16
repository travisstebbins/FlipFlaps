//Allison Snodgrass
//CSCE 121-505
//Splash_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Splash_window : Graph_lib::Window
{
	//constructor
		Splash_window(Point xy, int w, int h, const string& title);
	//functions
	private:
		//objects
			Color* baby_blue;
			Rectangle* bg_rect;
			Image* pancake_image;
			Text* title_label = new Text{Point{210,50}, "FlipFlaps"};
			Text* subtitle = new Text{Point{160,80}, "The Pancake Sorting Game!"};
			Text* team = new Text{Point{270,100}, "Team 37"};
			Text* trav = new Text{Point{35,170}, "Travis"};
			Text* steb = new Text{Point{20,195}, "Stebbins"};
			Text* sam = new Text{Point{210,155}, "Sam Stegall"};
			Text* alli = new Text{Point{460, 170}, "Allison"};
			Text* snod = new Text{Point{430, 195}, "Snodgrass"};
			Rectangle* next_button = new Rectangle{Point{540,460},50,30};
			Text* next_button_label = new Text{Point{550,480}, "Next"};
		//constants
		//functions
		
};

Splash_window::Splash_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title}
{
	baby_blue = new Color(fl_rgb_color(153,218,234));
	bg_rect = new Rectangle{Point{0,0}, 600, 500};
	bg_rect->set_fill_color(*baby_blue);
	attach(*bg_rect);
	pancake_image = new Image{Point{40, 130},"pancakes.jpg"};
	attach(*pancake_image);
	title_label = new Text{Point{210,50}, "FlipFlaps"};
	subtitle = new Text{Point{160,80}, "The Pancake Sorting Game!"};
	team = new Text{Point{270,100}, "Team 37"}; 
	title_label->set_font(Graph_lib::Font::screen_bold);
	title_label->set_font_size(40);
	title_label->set_color(Color::black);
	attach(*title_label);
	subtitle->set_font(Graph_lib::Font::screen_bold);
	subtitle->set_font_size(20);
	subtitle->set_color(Color::black);
	attach(*subtitle);
	team->set_font(Graph_lib::Font::screen_bold);
	team->set_font_size(15);
	team->set_color(Color::black);
	attach(*team);
	trav->set_font(Graph_lib::Font::screen_bold);
	trav->set_font_size(30);
	trav->set_color(Color::black);
	attach(*trav);
	steb->set_font(Graph_lib::Font::screen_bold);
	steb->set_font_size(30);
	steb->set_color(Color::black);
	attach(*steb);
	sam->set_font(Graph_lib::Font::screen_bold);
	sam->set_font_size(30);
	sam->set_color(Color::black);
	attach(*sam);
	alli->set_font(Graph_lib::Font::screen_bold);
	alli->set_font_size(30);
	alli->set_color(Color::black);
	attach(*alli);
	snod->set_font(Graph_lib::Font::screen_bold);
	snod->set_font_size(30);
	snod->set_color(Color::black);
	attach(*snod);
	next_button->set_fill_color(FL_BACKGROUND_COLOR);
	attach(*next_button);
	attach(*next_button_label);
}