#include <ncurses.h>
#include "piece.h"

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	height = 20;
	width = 10;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case 'q':
				
			case 'e':
				
			case 'a':
				
			case 's':
				
			case 'd':

			case default:	
		}
	}	
	endwin();			/* End curses mode		  */
	system("clear");
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');		

	wrefresh(local_win);		

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	

	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	
	wrefresh(local_win);
	delwin(local_win);
}
