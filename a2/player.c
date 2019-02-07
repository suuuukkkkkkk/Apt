#include "player.h"
/*initialise player's position*/
void initialisePlayer(Player * player, Position position, Direction direction)
{
    player->position = position;
    player->direction = direction;
    player->moves = 0;
}
/*Turn right 
  North -> East
  East -> South
  South -> West
  West -> North
  Turn left 
  North -> West
  West -> South
  South -> East
  East -> North*/
void turnDirection(Player * player, TurnDirection turnDirection)
{
	if(turnDirection == TURN_RIGHT){
		if(player->direction == NORTH){
			player->direction = EAST;
		}
		else if(player->direction == EAST){
			player->direction = SOUTH;
		}
		else if(player->direction == SOUTH){
			player->direction = WEST;
		}
		else if(player->direction == WEST){
			player->direction = NORTH;
		}
	}
	if(turnDirection == TURN_LEFT){
		if(player->direction == NORTH){
			player->direction = WEST;
		}
		else if(player->direction == WEST){
			player->direction = SOUTH;
		}
		else if(player->direction == SOUTH){
			player->direction = EAST;
		}
		else if(player->direction == EAST){
			player->direction = NORTH;
		}
	}
}

Position getNextForwardPosition(const Player * player)
{
  
    Position position;
	if(player->direction == NORTH){ /*player choose go foward when north,decrease x*/

        position = player->position;
        position.x --;
    }

    else if(player->direction == SOUTH){ /*player choose go foward when south,increase x*/

        position = player->position;
        position.x ++;
    }

    else if(player->direction == WEST){ /*player choose go foward when west,decrease y*/

        position = player->position;
        position.y --;
    }

    else if(player->direction == EAST){ /*player choose go foward when east,increase y*/

        position = player->position;
        position.y ++;
    }
    return position;
}

void updatePosition(Player * player, Position position)
{
   player->position = position;
}
/*get the initialise direction*/
void displayDirection(Direction direction)
{
     if (direction == NORTH) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH);
    }
	if (direction == SOUTH) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    if (direction == WEST) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_WEST);
    }
    
    if (direction == EAST) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_EAST);
    }
}
