#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
void counterClockwise(struct Piece *what);
void clockwise(struct Piece *what);
struct Piece {
	char type;		
	int currentRot;
	char rotations[4][4][4];
	int curX;
	int curY;
};
struct Piece *Piece_make(char type);
void Piece_destroy(struct Piece *what);
#endif
