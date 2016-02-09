#ifndef CURSESHEADER_H
#define CURSESHEADER_H

#include <curses.h>
#include <vector>

using namespace std;

class CurseSetup
{
public:
	void LoadColor();
	void setUp();
	void setupMainWindow();

private:
	enum class Color
	{
		None = 0,
		Red_Black = 1,
		Green_Black = 2,
		Magenta_Black = 3,
		Cyan_Black = 4,
		Yellow_Black = 5,
		White_Black = 6,
		White_Green = 7,
		White_Yellow = 8,
		White_Red = 9,
		Black_Black = 10,
		Yellow_Red = 11,
		Blue_Cyan = 12,
		Yellow_Cyan = 13,
		Blue_Green = 14,
		Green_Yellow = 15,
		Blue_Yellow = 16,
		Green_Cyan = 17,
		Black_Green = 18,
		White_Cyan = 19,
		Red_Blue = 20

	};


};

class ConsoleUI:public CurseSetup
{
public:
	 WINDOW *popUpwindow(int _length, int _width, int _startY, int _startX);

	 void delWin(WINDOW *win);
	 void printMenu(WINDOW *_win, int &_highlight, int _n_choices, char *_choices[]);

	 int selectMenu(WINDOW *win, char *menuItems[], int numberItems);

	 bool popUpcheck(char *menuChoice);

private:
	


};

class EddieCA:public ConsoleUI
{
public:
	EddieCA();
	void welcomeScreen();
	void menuScreen();
	void signIn();
	void displayLogo();
	void displayOddCell();
	void displayEvenCell();
	void displayRandomCell();
	void updateCellular(int oddArray[]);
	void displayCellular(int cellularArray[], int rowPos, WINDOW *cellularWin);
	void displayID();
	void displayStars();


private:
	char userName[80];
	string patternType;
	int updateLength = 30;
	vector<vector<char*>> logo;
	bool exit = true;
	
};

#endif 