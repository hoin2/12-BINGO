#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	
	printf("=====================================================\n");
	printf("*****************************************************\n");
	printf("                      BINGO GAME                     \n");
	printf("*****************************************************\n");
	printf("=====================================================\n\n\n");
	
	//generate numbers
	bingo_init();
	bingo_printBoard();

	//initialize bingo boards
	//while (game is not end)//줄수가 bingo보다 작음 
	/*
	{
		bingo_init(); 
		bingo_printBoard();
		//print no. of completed lines
		//select a propex number
		//put the number on the board
	}
	*/
		
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("=====================================================\n");
	printf("*****************************************************\n");
	printf("                  CONGRATULATION!!!!!                \n");
	printf("*#&$*#^&*$&^@($!@(*   BINGO!!!!!   #)!@*(#)*%$(#*)@*(\n");
	printf("                     YOU WIN!!!!!                    \n");
	printf("*****************************************************\n");
	printf("=====================================================\n\n");
	
	return 0;
}

/*
int get_number(void)
	{
		int selNum=0;
		
		do{
			printf("select a number :");
			scanf("%d",&selNum);
			fflush(stdin);
			
			if(bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT)
			{
				printf("%i is not on the board! select other one.\n",selNum);
			}
		}while(selNum<1||selNum>N_SIZE*N_SIZE||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT);
		
		return selNum;
	}

int bingo_checkNum(int selNum)
{
	
}
*/
