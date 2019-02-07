#include "game.h"


		
	
void playGame()
{
		while(1)
		{
		Cell board[BOARD_HEIGHT][BOARD_WIDTH];
		int i;
		int px;   /*position.x*/
		int py;		/*position.y*/
		char buffer[20];
		int length = 20;
		char s1[]="load 1";
		char s2[]="load 2";
		char *tok;
		char *endptr;
		Direction direction;
        Position position;
        Player *player;
		Player player1;
        player = &player1;
	
		do{
		
		fgets(buffer,length,stdin);
		
		/* prevent use input too much data*/
		for (i = 0 ; i < length; i++ )
		{
			if (buffer[i] == '\n')
			{
				break;
			}

			else if (i == length - 1)
			{
				printf("too much data\n");
				readRestOfLine();
			}
		}
		/*remove the \n character*/
	    buffer[strlen(buffer)-1] = '\0';
		/*display board 1*/
	if(strcmp(buffer,s1) == 0)
	{ 
		loadBoard(board, BOARD_1);
		displayBoard(board, NULL);
		printf("\n");
		initialiseCommands();
	}
	/*display board 2*/
	else if (strcmp(buffer,s2) == 0)
	{
		loadBoard(board, BOARD_2);
		displayBoard(board, NULL);
		printf("\n");
		initialiseCommands();
	}
	/*choose quit*/
	else if (strcmp(buffer,COMMAND_QUIT) == 0)
	{	
		return;
	}
	
	/*check in sequence :"init" "space" "x" "," "y" "," "direction"*/
	else if((tok = strtok(buffer, " ")) && strcmp(buffer, COMMAND_INIT) == 0){ 

                tok = NULL;  /*ready to check next input*/ 
				/*player input x */
                if ((tok = strtok(tok, ",")) != NULL) {

                    px = (int) strtol(tok, &endptr, 10);

                    if (px>= 0 && px <= 9) {
						
                        tok = NULL; /*ready to check next input*/ 
                        position.x = px; 
						
						/*player input y*/
                        if((tok = strtok(tok, ",")) != NULL){

                            py = (int) strtol(tok, &endptr, 10);

                            if(py >= 0 && py <= 9){

                                tok = NULL; /*ready to check next input*/ 

                                position.y = py; 

                                if((tok = strtok(tok, ",")) != NULL){

                                    /*get user input north south west east*/

                                    /* input is north*/
																				/*check position is empty*/
                                    if(strcmp(tok, DIRECTION_NORTH) == 0 && placePlayer(board, position) == TRUE){
                                        direction = NORTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        displayBoard(board, player);
                                        playGameCommands();
										game(player, board);
										break;
                                    }

                                    /*input is south*/

                                    else if(strcmp(tok, DIRECTION_SOUTH) == 0 && placePlayer(board, position) == TRUE){

                                        direction = SOUTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        displayBoard(board, player);
                                        playGameCommands();
                                        game(player, board);
										break;

                                    }

                                    /*input is west*/

                                    else if(strcmp(tok, DIRECTION_WEST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = WEST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);                                       
                                        displayBoard(board, player);
                                        playGameCommands();
										game(player, board);
										break;
                                    }

                                    /*if input is east*/

                                    else if(strcmp(tok, DIRECTION_EAST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = EAST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        displayBoard(board, player);
                                        playGameCommands();
                                        game(player, board);
										break;
                                    }

                                    /*if cell is blocked*/

                                    else if((strcmp(tok, DIRECTION_EAST) == 0 || strcmp(tok, DIRECTION_WEST) == 0 || strcmp(tok, DIRECTION_NORTH) == 0 || strcmp(tok, DIRECTION_SOUTH) == 0) && placePlayer(board, position) == FALSE){

                                        printf("The cell is blocked\n");

                                    }

                                    /*Checks the input of direction*/

                                    else if(strcmp(tok, DIRECTION_EAST) != 0 || strcmp(tok, DIRECTION_WEST) != 0 || strcmp(tok, DIRECTION_NORTH) != 0 || strcmp(tok, DIRECTION_SOUTH) != 0) {

                                        printf("Invalid input direction,please try again\n");

                                    }                               
                                }
                               
                                else {
                                
                                    printf("\nInvalid input,please try again\n");

                                }
                                }

                            else {

                                printf("\nInvalid input ,please try again\n");

                            }
                            }
                 
                        else {

                            printf("\nInvalid input,please try again\n");
                        }
                        }

                    else {

                        printf("\nInvalid input,please try again\n");

                    }
                    }

                else {

                    printf("\nInvalid input,please try again\n");

                }
                }	
            else
	{
		printf("\nInvalid Input,please try again\n");
	}
	}while (strcmp(buffer, COMMAND_QUIT) != 0);
        break;
	}
}


void game(Player *player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int i;
	char buffer[20];
	int length = 20;
	while(1)
	{
		do{
		fgets(buffer,length,stdin);
		
		/* prevent use input too much data*/
		for (i = 0 ; i < length; i++ )
		{
			if (buffer[i] == '\n')
			{
				break;
			}

			else if (i == length - 1)
			{
				printf("too much data\n");
				readRestOfLine();
			}
		}
		/* remove the \n character*/
	    buffer[strlen(buffer)-1] = '\0';
		/* turn left*/
		if (strcmp(buffer, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(buffer, COMMAND_TURN_LEFT) == 0) {

                turnDirection(player, TURN_LEFT);
                displayBoard(board, player);
                playGameCommands();

            }
			/*turn right*/
            else if (strcmp(buffer, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(buffer, COMMAND_TURN_RIGHT) == 0) {

                turnDirection(player, TURN_RIGHT);
                displayBoard(board, player);
                playGameCommands();

            }
			/* go forward*/
            else if (strcmp(buffer, COMMAND_FORWARD) == 0 || strcmp(buffer, COMMAND_FORWARD_SHORTCUT) == 0){

                movePlayerForward(board, player);
                displayBoard(board, player);
                playGameCommands();
                player->moves ++;

            }
			/*get total moves ,when quit*/
            else if (strcmp(buffer, COMMAND_QUIT) == 0) {

                printf("Total player moves:%d\n", player->moves);
            }
			 else
	{
		printf("\nInvalid Input,please try again\n");
	}
	}while (strcmp(buffer, COMMAND_QUIT) != 0);
        break;
	}
}
		
		
	
/*initialise game menu*/
void initialiseCommands()
{
		printf("load <g>\n");
		printf("init <x>,<y>,<direction>\n");
		printf("quit\n");
}
/* play game menu*/		
void playGameCommands()
{
		printf("forward\n");
		printf("turn_left(or l)\n");
		printf("turn_right(or r)\n");
		printf("quit\n");
}    

   

