#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"


#define BINGO_NUMSTATUS_ABSENT	-1
#define N_LINE					2
#define N_SIZE					5
#define BINGO_RES_UNFINISHED	0
#define BINGO_RES_FINISHIED		1

int get_number(void)
{
	int selNum=0;
		
	do{
		printf("select a number :");
		scanf("%d",&selNum);
		fflush(stdin);
			
		if(selNum<1||selNum>N_SIZE*N_SIZE||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT)			
		{
			printf("%i is not on the board! select other one.\n",selNum);
		}
	}while(selNum<1||selNum>N_SIZE*N_SIZE||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT);
		
	return selNum;
}
	
int check_gameEnd(void)
{
	int res = BINGO_RES_UNFINISHED;
	if (bingo_countCompletedLine()>=N_LINE)
		res = BINGO_RES_FINISHIED;
		
	return res;
}

int main(int argc, char *argv[]) {
	int selNum;
	
	srand((unsigned)time(NULL));
	
	printf("=====================================================\n");
	printf("*****************************************************\n");
	printf("                      BINGO GAME                     \n");
	printf("*****************************************************\n");
	printf("=====================================================\n\n\n");
	
	//generate numbers
	bingo_init();
	
	//initialize bingo boards
	while (check_gameEnd()==BINGO_RES_UNFINISHED)//줄수가 bingo보다 작음 
	{
		bingo_printBoard();
		
		//select a propex number
		selNum = get_number();
		
		//put the number on the board
		bingo_inputNum(selNum);
		
		//print no. of completed lines
		printf("No.of copleted line : %i\n",bingo_countCompletedLine());
		
	}

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





