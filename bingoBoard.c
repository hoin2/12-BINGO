#include "bingoBoard.h"
#include <stdlib.h>
				

static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

int bingo_checkNum(int selNum)
{
	if(numberStatus[selNum-1]==BINGO_NUMSTATUS_ABSENT)
		return BINGO_NUMSTATUS_ABSENT;
}

void bingo_init(void)
{
	int i,j,k;
	int randNum;
	int maxNum=N_SIZE*N_SIZE;
	
	numberStatus[N_SIZE*N_SIZE]=BINGO_NUMSTATUS_ABSENT;
	
	for(i=0;i<N_SIZE*N_SIZE;i++)
		numberStatus[i]=BINGO_NUMSTATUS_ABSENT;
	
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++)
		{
			randNum=rand()%maxNum;
			
			for(k=0;k<N_SIZE*N_SIZE;k++)
			{
				if(numberStatus[k]==BINGO_NUMSTATUS_ABSENT)
				{
					if(randNum==0)
						break;
					else
						randNum--; 
				}
			}
			bingoBoard[i][j]=k+1;
			numberStatus[k]=N_SIZE*i+j;
			maxNum--;
		}
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
	int r_index;
	int c_index;
	
	r_index=numberStatus[sel-1]/N_SIZE;
	c_index=numberStatus[sel-1]%N_SIZE;
	bingoBoard[r_index][c_index]=BINGO_NUMSTATUS_ABSENT;
	numberStatus[sel-1]=BINGO_NUMSTATUS_ABSENT;
	
}

int bingo_countCompletedLine(void)
{
	int i,j;
	int cnt=0;
	int checkBingo;
	
	//check col
	for(j=0;j<N_SIZE;j++){
		checkBingo=1;
		for(i=0;i<N_SIZE;i++){
			if(bingoBoard[i][j]>0){
				checkBingo=0;
				break;
			}
		}
	if (checkBingo == 1)
			cnt++;
	}
	
	//check diogonal
	for(i=0;i<N_SIZE;i++){
		checkBingo=1;
		if(bingoBoard[i][i]>0){
			checkBingo=0;
			break;
		}
	}
	if (checkBingo == 1)
		cnt++;
	
	for(i=0;i<N_SIZE;i++){
	
		if(bingoBoard[i][N_SIZE-i-1]>0){
			checkBingo=0;
			break;
		}
	}
	if (checkBingo == 1)
		cnt++;
	
	//check row
	for(i=0;i<N_SIZE;i++){
		checkBingo=1;
		for(j=0;j<N_SIZE;j++){
			if(bingoBoard[i][j]>0){
				checkBingo=0;
				break;
			}
		}
		if (checkBingo == 1){
			cnt++;
		}
	}
	
	return cnt;
}


