#include "piece.h"
#include <assert.h>
#include <stdlib.h>

struct Piece *Piece_make(char type, int curX, int curY)
{
	struct Piece *what = malloc(sizeof(struct Piece));
	assert(what != NULL);

	what->type = type;
	what->curX = curX;
	what->curY = curY;
	what->currentRot = 0;
	switch(type) {
		case 'I':
			what->rotations = {"####",
					   "    ",
					   "    ",
					   "    ",
					   
					   "#   ",
					   "#   ",
					   "#   ",
					   "#   ",
					
					   "####",
					   "    ",
					   "    ",
					   "    ",
					
					   "#   ",
					   "#   ",
					   "#   ",
					   "#   "};
			
		case 'J':
			what->rotations = {" #  ",
					   " #  ",
					   "##  ",
					   "    ",

					   "#   ",
					   "### ",
					   "    ",
					   "    ",
					
					   "##  ",
					   "#   ",
					   "#   ",
					   "    ",
					
					   "### ",
					   "  # ",
					   "    ",
					   "    "};

		case 'L':
			what->rotations = {"#   ",
					   "#   ",
					   "##  ",
					   "    ",

					   "### ",
					   "#   ",
					   "    ",
					   "    ",
					
					   "##  ",
					   " #  ",
					   " #  ",
					   "    ",
					
					   "  # ",
					   "### ",
					   "    ",
					   "    "};
		case 'O':
			what->rotations = {"##  ",
					   "##  ",
					   "    ",
					   "    ",

					   "##  ",
					   "##  ",
					   "    ",
					   "    ",
					
					   "##  ",
					   "##  ",
					   "    ",
					   "    ",
					
					   "##  ",
					   "##  ",
					   "    ",
					   "    ";
		case 'S':	
			what->rotations = {" ## ",
					   "##  ",
					   "    ",
					   "    ",

					   "#   ",
					   "##  ",
					   " #  ",
					   "    ",
					
					   " ## ",
					   "##  ",
					   "    ",
					   "    ",
					
					   "#   ",
					   "##  ",
					   " #  ",
					   "    "};
		case 'Z':
			what->rotations = {"##  ",
					   " ## ",
					   "    ",
					   "    "

					   " #  ",
					   "##  ",
					   "#   ",
					   "    ",
					
					   "##  ",
					   " ## ",
					   "    ",
					   "    ",
					
					   " ## ",
					   "### ",
					   "# # ",
					   "  # "};
			
		case 'T':
			what->rotations = {"### ",
					   " #  ",
					   "    ",
					   "    ",

					   " #  ",
					   "##  ",
					   " #  ",
					   "    ",
					
					   " #  ",
					   "### ",
					   "    ",
					   "    ",
				
					   "#   ",
					   "##  ",
					   "#   ",
					   "    "};
	}
	return what;
}

void Piece_destroy(struct Piece *what)
{
	assert(what != NULL);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			free(what->rotatrions[i][j]);
		}
	}
	free(what->rotations);
	free(what);
}

void Clockwise(struct Piece *what)
{
	what->currentRot++;
	if (what->currentRot > 3)
		what->currentRot = 0;
}
void counterClockwise(struct Piece *what)
{
	what->currentRot--;
	if (what->currentRot < 0)
		what->currentRot = 3;
}
