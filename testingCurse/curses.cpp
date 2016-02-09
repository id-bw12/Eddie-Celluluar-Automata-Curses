#include <curses.h>
#include "cursesHeader.h"

WINDOW* ConsoleUI::popUpwindow(int _length, int _width, int _startY, int _startX)
{
	WINDOW *win = newwin(_length, _width, _startY, _startX);

	wbkgd(win,A_BOLD|COLOR_PAIR(6));
	box(win, 0, 0);
	wrefresh(win);

	return win;
}

void ConsoleUI::delWin(WINDOW *_win)
{
	box(_win, ' ', ' ');

	wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

	werase(_win);
	wrefresh(_win);
	delwin(_win);
}

int ConsoleUI::selectMenu(WINDOW *_win, char *_menuItems[],int numberItems)
{
	int ch, n_choices = numberItems, choice = 0, highlight = 1;

	keypad(_win, true);

	printMenu(_win, highlight, n_choices, _menuItems);

	while (1)
	{
		ch = wgetch(_win);
		switch (ch)
		{
		case KEY_UP:
			if (highlight == 1)
				highlight = n_choices;
			else
				--highlight;
			break;
		case KEY_DOWN:
			if (highlight == n_choices)
				highlight = 1;
			else
				++highlight;
			break;

		case 13:
			choice = highlight;
			break;

		default:
			mvprintw(45, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", ch, ch);
			refresh();
			break;
		}
		printMenu(_win, highlight, n_choices, _menuItems);
		if (choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}

	return choice;
}

bool ConsoleUI::popUpcheck(char *menuChoice)
{
	char *menuItems[] = {"Yes","No"};

	int menuItemSelection;

	bool userChoice = false;

	WINDOW *win = popUpwindow(10, 40, 20, 29);

	wattron(win, A_BOLD);
	mvwprintw(win, 2, 2, "You have selected <%s>", menuChoice,".");
	mvwprintw(win, 3, 2, "Are you sure you want to continue?");
	wattroff(win, A_BOLD);
	menuItemSelection = selectMenu(win, menuItems, 2);

	if (menuItemSelection == 1)
		userChoice = true;
		
	werase(win);

	return userChoice;

}

void ConsoleUI::printMenu(WINDOW *_win, int &_highlight, int _n_choices, char *_choices[])
{
	int x = 2, y = 4, i;

	box(_win, 0, 0);
	for (i = 0; i < _n_choices; ++i)
	{
		if (_highlight == i + 1) /* High light the present choice */
		{
			wattron(_win, A_REVERSE);
			mvwprintw(_win, y, x, "%s", _choices[i]);
			wattroff(_win, A_REVERSE);
		}
		else
			mvwprintw(_win, y, x, "%s", _choices[i]);
		++y;
	}
	wrefresh(_win);
}
