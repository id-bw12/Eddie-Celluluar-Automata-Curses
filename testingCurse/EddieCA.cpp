#include "cursesHeader.h"
#include <curses.h>
#include <time.h>

using namespace std;

EddieCA::EddieCA() :logo(24, vector<char*>(60))
{
	setUp();
}

void EddieCA::welcomeScreen()
{
	WINDOW *welcomeWin = popUpwindow(15,95,1,2);
	wattron(welcomeWin, WA_BOLD);
	mvwprintw(welcomeWin, 1, 2, "  __          __  _                            _          ______    _     _ _      _     ");
	mvwprintw(welcomeWin, 2, 2, "  \\ \\        / / | |                          | |        |  ____|  | |   | (_)    ( )    ");
	mvwprintw(welcomeWin, 3, 2, "   \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |__   __| | __| |_  ___|/ ___ ");
	mvwprintw(welcomeWin, 4, 2, "    \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  |  __| / _` |/ _` | |/ _ \\ / __|");
	mvwprintw(welcomeWin, 5, 2, "     \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |___| (_| | (_| | |  __/ \\__ \\");
	mvwprintw(welcomeWin, 6, 2, "    __\\/_ \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/\  |______\\__,_|\\__,_|_|\\___| |___/");
	mvwprintw(welcomeWin, 7, 2, "  / ____|   | | |     | |                /\\        | |                      | |         ");
	mvwprintw(welcomeWin, 8, 2, " | |     ___| | |_   _| | __ _ _ __     /  \\  _   _| |_ ___  _ __ ___   __ _| |_ __ _   ");
	mvwprintw(welcomeWin, 9, 2, " | |    / _ \\ | | | | | |/ _` | '__|   / /\\ \\| | | | __/ _ \\| '_ ` _ \\ / _` | __/ _` |  ");
	mvwprintw(welcomeWin, 10, 2," | |___|  __/ | | |_| | | (_| | |     / ____ \\ |_| | || (_) | | | | | | (_| | || (_| |  ");
	mvwprintw(welcomeWin, 11, 2,"  \\_____\\___|_|_|\\__,_|_|\\__,_|_|    /_/    \\_\\__,_|\\__\\___/|_| |_| |_|\\__,_|\\__\\__,_| ");
	wattroff(welcomeWin, WA_BOLD);
	wrefresh(welcomeWin);
}

void EddieCA::menuScreen()
{

	char *menuOptions[] = {"Sign In","Logo","Old Cell Pattern","Even Cell Pattern", "Random Cell Pattern" , "ID Information", "Stars","Exit"};
	
	int choice;

	welcomeScreen();

	keypad(stdscr, TRUE);

	WINDOW *menuWin = popUpwindow(15, 40, 20, 29);

	mvwprintw(menuWin, 1, 15, "Menu options.");
	mvwprintw(menuWin, 13, 1, "Not signed in.");


	while (exit)
	{
		choice = selectMenu(menuWin, menuOptions, 8);

		if (popUpcheck(menuOptions[choice-1]))
		{
			switch (choice - 1)
			{
			case 0:
				signIn();
				mvwprintw(menuWin,13, 1, "Currently sign in as %s", userName);
				break;

			case 1:
				displayLogo();
				break;

			case 2:
				displayOddCell();
				break;

			case 3:
				displayEvenCell();
				break;
				
			case 4:
				displayRandomCell();
				break;

			case 5:
				displayID();
				break;

			case 6:
				displayStars();
				break;
				
			case 7:
				exit = false;
				break;

			default:
				break;
			}
		}

	}

}

void EddieCA::signIn()
{
	curs_set(1);
	echo();

	WINDOW *signInWin = popUpwindow(10, 45, 20, 28);
	mvwprintw(signInWin, 2, 10, "Please enter in your name.");
	wattron(signInWin, WA_BOLD | WA_BLINK);
	mvwprintw(signInWin, 8, 10, "Hit Enter to Continue.");
	wattroff(signInWin, WA_BOLD | WA_BLINK);
	wrefresh(signInWin);

	WINDOW *signInBox = popUpwindow(3, 43, 24, 29);
	mvwprintw(signInBox, 1, 1, " ");

	wgetstr(signInBox, userName);

	curs_set(0);
	noecho();

	signInWin = popUpwindow(10, 45, 20, 28);
	mvwprintw(signInWin, 3, 1, "Thank you for joining us %s.", userName);
	wgetch(signInWin);

	delWin(signInWin);
}

void EddieCA::displayLogo()
{
	WINDOW *logoWin = popUpwindow(30,65,18,18);

	mvwprintw(logoWin, 1, 24, "Eddie's Logo");
	mvwprintw(logoWin, 3, 1, "                .., dkooooookxdc'.	             \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 4, 1, "            .'donxd. .ckwmmmmmmmmmn0c		     \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 5, 1, "          'xxwmmmmmnx'  :onmmmmmmmmwk. c;.          \333\333"); 
	mvwprintw(logoWin, 6, 1, "        ;owmmmmmmmmmmw0c. 'okwmmmmmmx. onkl. 	     \333\333"); 
	mvwprintw(logoWin, 7, 1, "      ,owmmmmmwwwnxxk0oxd,  .;knmmmmn. ;nmwxc.	     \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 8, 1, "     .ool;,,,''....            .,dkwn; 'xmmmwo.     \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 9, 1, "    ....,;;;ldl.                   ;kc .kmmmmmk,    \333\333"); 
	mvwprintw(logoWin, 10, 1, "  .xwmmmmmmmwd.                      .  0mmmmmmk'   \333\333"); 
	mvwprintw(logoWin, 11, 1, "  cnmmmmmmmn:                           dwmmmmwx:   \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 12, 1, " .kmmmmmmmn:                            dwmmmnd. .  \333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 13, 1, " ,nmmmmmw0,                             ;nmwk. .kx."); 
	mvwprintw(logoWin, 14, 1, " cnmmmmxc.                              .k0:  cxw0. \333        \333"); 
	mvwprintw(logoWin, 15, 1, " cnmmwx._':                             .c. ;0wmmk. \333\333      \333\333"); 
	mvwprintw(logoWin, 16, 1, " ,nwo,_.dw0                               .kwmmmwk. \333\333\333    \333\333\333"); 
	mvwprintw(logoWin, 17, 1, " .oc  cxmmx.                            .lxmmmmmnc  \333\333\333\333  \333\333\333\333"); 
	mvwprintw(logoWin, 18, 1, "    ;kwmmmx;                           :kwmmmmmmk.  \333\333\333\333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 19, 1, "   owmmmmmn;                         ,0wmmmmmmmn,   \333\333\333\333\333\333\333\333\333\333"); 
	mvwprintw(logoWin, 20, 1, "   .0wmmmmwd .o;                   .xnwwwmwmmwk;    \333\333  \333\333  \333\333"); 
	mvwprintw(logoWin, 21, 1, "    .kwmmmwo .kw0c.               .ll:::,......     \333\333      \333\333"); 
	mvwprintw(logoWin, 22, 1, "      :kwmmk. dwmmxd'        .....',;;;:lllo'	     \333\333      \333\333"); 
	mvwprintw(logoWin, 23, 1, "       .lkwk. ;nmmmmwo:. .l0xnnnnnwwmmmmwnx.	     \333\333	     \333\333"); 
	mvwprintw(logoWin, 24, 1, "         .:d' 'nmmmmmmmkl. .ckwmmmmmmmwko."); 
	mvwprintw(logoWin, 25, 1, "              .0wwmmmmmmmno:  ,xnmwnoo'"); 
	mvwprintw(logoWin, 26, 1, "              .;oxokxnnnnxo;  .:'."); 
	mvwprintw(logoWin, 27, 1, "                     ....."); 
	mvwprintw(logoWin, 28, 10, "Hit Enter to go back to the menu screen.");
	wgetch(logoWin);
	delWin(logoWin);
}

void EddieCA::displayOddCell()
{
	int childArray[80];
	patternType = "Old";

	for (int i = 0; i < 80; i++)
		childArray[i] = 0;

	childArray[39] = 1;

	updateCellular(childArray);
}

void EddieCA::displayEvenCell()
{
	int childArray[80];
	patternType = "Even";

	for (int i = 0; i < 80; i++)
		childArray[i] = 0;

	childArray[38] = 1; childArray[40] = 1;

	updateCellular(childArray);
}

void EddieCA::displayRandomCell()
{
	int childArray[80];
	srand(time(0));

	patternType = "Old";

	for (int i = 0; i < 80; i++)
		childArray[i] = rand() % 2;

	updateCellular(childArray);

}

void EddieCA::updateCellular(int oldArray[])
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/

	int parentArray[80];
	int count,
		same = 1;

	/**************************************************************************************/
	
	WINDOW *cellularWin = popUpwindow(32,81,17,10);
	nodelay(cellularWin, TRUE);
	displayCellular(oldArray, same, cellularWin);
	do
	{
		
		for (int i = 0; i < 80; i++)
			parentArray[i] = oldArray[i];

		for (int j = 0; j < 80; j++)
		{
			if (j == 0)
				count = parentArray[j] + parentArray[j + 1];
			else
				if (j == 79)
					count = parentArray[j - 1] + parentArray[j];
				else
					count = parentArray[j - 1] + parentArray[j] + parentArray[j + 1];

			if (patternType == "Old") 
				oldArray[j] = count % 2;
			else
			{
				if (count == 2 || count == 0)
					oldArray[j] = 1;
				else
					oldArray[j] = 0;
			}
		}

		same++;
		displayCellular(oldArray, same, cellularWin);
	} while (same < updateLength);

	nodelay(cellularWin, false);
	wgetch(cellularWin);

	delWin(cellularWin);
}

void EddieCA::displayCellular(int cellularArray[], int rowPos, WINDOW *cellularWin)
{
	for (int i = 1; i < 81; i++)
	{
		switch (cellularArray[i])
		{
		case 0:
			mvwprintw(cellularWin, rowPos, i, " ");
			break;

		case 1:
			mvwprintw(cellularWin, rowPos, i, "\333");
			wrefresh(cellularWin);
			napms(150);
			break;

		default:
			break;
		}
	}	
}

void EddieCA::displayID()
{
	WINDOW *idWin = popUpwindow(16, 52, 20, 24);
	mvwprintw(idWin, 1, 19, "ID INFORMATION");
	mvwprintw(idWin, 2, 3, "Programmers		  :	Eddie Meza Jr.");
	mvwprintw(idWin, 3, 3, "Assignment #		  :	TA #13CA");
	mvwprintw(idWin, 4, 3, "Assignment name	  :	Celluluar Automata");
	mvwprintw(idWin, 5, 3, "Course # and Title	  :	CISC 205 - OOPS");
	mvwprintw(idWin, 6, 3, "Class Meeting Time	  :	TTh 9:35 - 12:35");
	mvwprintw(idWin, 7, 3, "Instructor		  :	Professor Forman");
	mvwprintw(idWin, 8, 3, "Hours		  :	7h");
	mvwprintw(idWin, 9, 3, "Difficulty		  :	5");
	mvwprintw(idWin, 10, 3, "Completion Date	  :	09/07/2014");
	mvwprintw(idWin, 11, 3, "Project Name		  :	Eddie's Cellular");
	wgetch(idWin);
	delWin(idWin);
}

void EddieCA::displayStars()
{
	WINDOW *starsWin = popUpwindow(29, 91, 20, 5);

	mvwprintw(starsWin, 1, 40, "Stars");
	mvwprintw(starsWin, 2, 3, "1.Allow only one sign-in. Alert user it can’t be done if user tries again.");
	mvwprintw(starsWin, 3, 3, "2.Only proceed after sign-in is done, although it’s okay to exit");
	mvwprintw(starsWin, 4, 3, "3.Only proceed if sign - in is done first, although it’s okay to exit");
	mvwprintw(starsWin, 5, 3, "4.Allow only 3 invalid menu entries after which program exits");
	mvwprintw(starsWin, 6, 3, "5.Expand previous STAR to warn user at 3rd invalid entry that");
	mvwprintw(starsWin, 7, 3, "4.Allow only 3 invalid menu entries after which program “exits” program will exit if");
	mvwprintw(starsWin, 8, 3, "the 4th try is invalid.");
	mvwprintw(starsWin, 9, 3, "6.Instead of re - writing the menu for Sorry message, be ecological and move the cursor");
	mvwprintw(starsWin, 10, 3, "back to the prompt point, but be sure to pause for a moment and then erase the now");
	mvwprintw(starsWin, 11, 3, "unnecessary“Sorry” part of the message.");
	mvwprintw(starsWin, 12, 3, "7.Expand previous STAR to be ecological for all appropriate menu selections");
	mvwprintw(starsWin, 13, 3, "8.Display the cellular output fully across 25 rows and 80 columns");
	mvwprintw(starsWin, 14, 3, "9.When user selects C, play Celebration - type of music and stop it when menu reappears");
	mvwprintw(starsWin, 15, 3, "10.Display all the rows and columns with a space for 0's and an interesting extended");
	mvwprintw(starsWin, 16, 3, "ASCII graphics character, like \333, for each 1.");
	mvwprintw(starsWin, 17, 3, "11.Expand previous STAR by using color for the special ASCII graphics character.");
	mvwprintw(starsWin, 18, 3, "(representing the 1's).");
	mvwprintw(starsWin, 19, 3, "12.When C is selected, prompt user for number of rows to be displayed instead of");
	mvwprintw(starsWin, 20, 3, "automatically showing 22 rows.");
	mvwprintw(starsWin, 21, 3, "13.Add another menu item that can randomly seed all the cells in the first row");
	mvwprintw(starsWin, 22, 3, "and then displays the resulting 22 row pattern.");
	mvwprintw(starsWin, 23, 3, "14.(2)Experiment with different rules and select one that you find especially");
	mvwprintw(starsWin, 24, 3, "appealing to be included as another menu item. Use any seeding you wish, but");
	mvwprintw(starsWin, 25, 3, "experiment with several and describe – in a brief screen output message – any");
	mvwprintw(starsWin, 26, 3, "oddities you find.");
	mvwprintw(starsWin, 27, 3, "Total Stars: 15");

	wgetch(starsWin);
	delWin(starsWin);
}
