#include "bingoBoard.h"
#include <stdlib.h>

#define BINGO_NUMSTATUS_ABSENT		-1
#define BINGO_NUMSTATUS_PRESENT		0


int bingoBoard[N_SIZE][N_SIZE];


void bingo_init(void)
{
	int i, j;
	int cnt=1;
	
	for(i=0;i<N_SIZE;i++)
		for(j=0;j<N_SIZE;j++)
		{
			if(cnt==15)
			{
				bingoBoard[i][j]=BINGO_NUMSTATUS_ABSENT;
				cnt++;
			}
			else
				bingoBoard[i][j]=cnt++;
		}
}

void bingo_printBoard(void)
{
	int i,j;
	
	printf("=====================================\n");
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++){
			if(bingoBoard[i][j]>0)			//if(bingoBoard[i][j]==BINGO_NUMSTATUS_ABSENT)
				printf("%i\t",bingoBoard[i][j]);
			else
				printf("X\t");
		}
		printf("\n");
	}
	printf("=====================================\n");
}

void bingo_inputNum(int sel)
{
		
}
/*
int bingo_countCompletedLine(void)
{
	int i,j;
	int cnt=0;
	int checkBigo;
	
	
	 
	
	//check row
	for(i=0;i<N_SIZE;i++){
		int checkBingo=1;
		for(j=0;j<N_SIZE;j++)
			if(bingoBoard[i][j]>0){
				checkBingo=0;
				break;
			}
	}
	if(checkBingo==1)
		cnt++;
}

int check_gameEnd(void){
	
	int res = BINGO_RES_UNFINISHED;
}
*/
