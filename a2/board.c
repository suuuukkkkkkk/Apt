#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};
/*get the empty board*/
void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int x;
	int y;
	for(x = 0; x < BOARD_HEIGHT; x++)
	{

		for (y = 0; y < BOARD_WIDTH; y++)
		{
			board[x][y]=EMPTY;
			
		}
		
	}
}
/*get the block board*/
void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
   int x;
	int y;
	for(x = 0; x < BOARD_HEIGHT; x++)
	{

		for (y = 0; y < BOARD_WIDTH; y++)
		{
			board[x][y]=boardToLoad[x][y];
			
		}
		
	}
}
/*check the cell is empty*/
Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    if(board[position.x][position.y] == BLOCKED) {

        return FALSE;

    }

    else

        board[position.x][position.y] = PLAYER;
        return TRUE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
	Position position = getNextForwardPosition(player);
	if(position.x < 0 || position.x > 9 || position.y > 9 || position.y < 0){
		printf("The car is at the edge of the board and cannot move further in that direction\n");
		return OUTSIDE_BOUNDS;
	}
	else if(board[position.x][position.y] == BLOCKED){
		printf("Error : cannot move forward because the road is blocked.\n");
		return CELL_BLOCKED;
	}
	else{
	board[player->position.x][player->position.y] = EMPTY;
	updatePosition(player, position);
    board[player->position.x][player->position.y] = PLAYER;
    return PLAYER_MOVED;
	}
}
/* the function can display board*/
void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
	int x;
	int y;
    printf("| |0|1|2|3|4|5|6|7|8|9|\n");
	for(x = 0; x < BOARD_HEIGHT; x++)
	{

		printf("|%d|",x);

		for (y = 0; y < BOARD_WIDTH; y++)
		{
			 if (board[x][y] == EMPTY){

                printf("%s|", EMPTY_OUTPUT);
            }
             if (board[x][y] == BLOCKED){

                printf("%s|", BLOCKED_OUTPUT);
            }
			if (board[x][y] == PLAYER){

                displayDirection(player->direction);

            }
		}
		printf("\n");/*make ten lines*/
	}	
}
