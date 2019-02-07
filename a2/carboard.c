#include "carboard.h"

int main(void)
{
    while(1)
	{
        int i;
		char buffer[3];
		int length = 3;
		int choice;
		/*limited input one word*/
		displayMainMenu();

		/* get the selection from the main menu */
		
		fgets(buffer,length,stdin);
		
		/* prevent user input too much data*/
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
		/*char to int*/
		choice = atoi(buffer);

		/* choose tasks */
		switch(choice)
		{
		case 1:
			startGame();  /*play game*/
			break;

		case 2:
			showStudentInformation(); 
			printf("--------------------------\n");
			break;

		case 3:
			/* quit the program */
			exit(0);
			break;
			
	    default:
		    printf("invalid input,please enter again.\n");
			break;

		}


	}

	return EXIT_SUCCESS;
}

void startGame()
{
			Cell board[BOARD_HEIGHT][BOARD_WIDTH];
			information();
			initialiseBoard(board);
			displayBoard(board, NULL);
			printf("\n");
			printf("enter you commands\n");
			printf("load <g> or quit\n");
			playGame();
}	

void showStudentInformation()
{
   	printf("Name: %s\n", STUDENT_NAME);
	printf("No: %s\n", STUDENT_ID);
	printf("Email: %s \n", STUDENT_EMAIL);
}

void displayMainMenu()
{

	printf("\nWelcome to Car Board!\n");
	printf("--------------------------\n");
	printf("1. Play a game\n");
	printf("2. Show student's information\n");
	printf("3. Quit\n");
	printf("\nPlease enter your choice: \n");

}
void information()
{
	printf("You can use the following commands to play the game:\n");
	printf("load<g>\n");
	printf("    g:number of the game board to load<g>\n");
	printf("init <x>,<y>,<direction>\n");
	printf("	x:horizontal position of the car on the board (between 0&9)\n");
	printf("	y:vertical position of the car on the board (between 0&9)\n");
	printf("	direction: direction of the car's movement (north, east, south, west)\n");
	printf("forward (or f)\n");
	printf("turn_left (or l)\n");
	printf("turn_right (or r)\n");
	printf("quit\n");
}
