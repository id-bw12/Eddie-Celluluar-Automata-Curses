#include "cursesHeader.h"
#include <curses.h>

using namespace std;

void signIn();

int main()
{
	EddieCA *startCA = new EddieCA();

	startCA->menuScreen();

	endwin();			/* End curses mode		  */
	return 0;
}