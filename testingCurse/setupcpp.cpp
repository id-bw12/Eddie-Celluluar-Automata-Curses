#include "cursesHeader.h"
#include <curses.h>

void CurseSetup::setUp()
{
	initscr();		
	raw();
	curs_set(0);
	noecho();
	clear();

	setupMainWindow();
	LoadColor();
}

void CurseSetup::setupMainWindow()
{
	resize_term(55, 100);
	bkgd(COLOR_PAIR(6));
	refresh();
}

void CurseSetup::LoadColor()
{
	start_color();
	init_pair(static_cast<int>(Color::Red_Black), COLOR_RED, COLOR_BLACK);
	init_pair(static_cast<int>(Color::Green_Black), COLOR_GREEN, COLOR_BLACK);
	init_pair(static_cast<int>(Color::Yellow_Red), COLOR_YELLOW, COLOR_RED);
	init_pair(static_cast<int>(Color::Cyan_Black), COLOR_CYAN, COLOR_BLACK);
	init_pair(static_cast<int>(Color::Yellow_Black), COLOR_YELLOW, COLOR_BLACK);
	init_pair(static_cast<int>(Color::White_Black), COLOR_WHITE, COLOR_BLACK);
	init_pair(static_cast<int>(Color::White_Green), COLOR_WHITE, COLOR_GREEN);
	init_pair(static_cast<int>(Color::White_Yellow), COLOR_BLACK, COLOR_YELLOW);
	init_pair(static_cast<int>(Color::White_Red), COLOR_WHITE, COLOR_RED);
	init_pair(static_cast<int>(Color::Black_Black), COLOR_BLACK, COLOR_BLACK);
	init_pair(static_cast<int>(Color::Magenta_Black), COLOR_MAGENTA, COLOR_BLACK);
	init_pair(static_cast<int>(Color::Blue_Cyan), COLOR_BLUE, COLOR_CYAN);
	init_pair(static_cast<int>(Color::Yellow_Cyan), COLOR_YELLOW, COLOR_CYAN);
	init_pair(static_cast<int>(Color::Blue_Green), COLOR_BLUE, COLOR_GREEN);
	init_pair(static_cast<int>(Color::Green_Yellow), COLOR_GREEN, COLOR_YELLOW);
	init_pair(static_cast<int>(Color::Blue_Yellow), COLOR_BLACK, COLOR_YELLOW);
	init_pair(static_cast<int>(Color::Green_Cyan), COLOR_GREEN, COLOR_CYAN);
	init_pair(static_cast<int>(Color::Black_Green), COLOR_BLACK, COLOR_GREEN);
	init_pair(static_cast<int>(Color::White_Cyan), COLOR_WHITE, COLOR_CYAN);
	init_pair(static_cast<int>(Color::Red_Blue), COLOR_RED, COLOR_BLUE);

}