#include <ncurses.h>
#include "pieces.h"

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main(int argc, char *argv[])
{	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;
	int score = 0;
	int isOver = FALSE;

	initscr();			
	cbreak();			
	keypad(stdscr, TRUE);		

	height = 20;
	width = 10;
	starty = (LINES - height) / 2;	// Puts the tetris screen in the center no matter what
	startx = (COLS - width) / 2;
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while(isOver == FALSE && (ch = getch()) != KEY_F(1)) //checks if F1 is pressed for a way to quit
	{	switch(ch) //
		{	case 'q':
				
			case 'w':
				
			case 'e':
				
			case 'a':

			case 's':
				
			case 'd':
					
		}
		
	}
	
	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		
	wrefresh(local_win);		
	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' '); //The more verbose border method is needed here to make sure the corners are deleted.
	wrefresh(local_win);
	delwin(local_win);
}