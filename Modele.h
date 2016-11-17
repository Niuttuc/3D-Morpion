#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
typedef int *** board;
typedef int ** grid;
typedef int * stack;
board create_board(int n)
{
	int i=0,j=0,k=0;
	board mainBoard=(board)calloc(n,sizeof(long int));
	for (i=0;i<n;i=i+1)
	{
		grid gridAdress=(grid)calloc(n,sizeof(long int));
		mainBoard[i]=gridAdress;
		for (j=0;j<n;j=j+1)
		{
			stack stackAdress=calloc(n+1,sizeof(int));
			mainBoard[i][j]=stackAdress;
			for (k=0;k<n;k=k+1)	stackAdress[k]=0;
			stackAdress[n]=['\1'];
		}		
	}
	return (board) mainBoard;
}

int addItem(int item, board bo, int x, int y, int stackSize)
{
	if (board[x][y][stackSize]=='\1')
	{
		int i=0;
		stack stackAdress=calloc(2*stackSize+1,sizeof(int));
		
		for (i=0,i<stackSize,i=i+1)
			stackAdress[i]=bo[x][y][i];
		for (i=stackSize,i<2*stackSize,i=i+1)
			stackAdress[i]=0;
		stackAdress[2*stackSize]='\1';
		bo[x][y]=stackAdress;
	}
	bo[x][y][stackSize]=item;
	return 1;
}

int remItem(board bo, int x, int y, int stackSize)
{
	if (stackSize>0)
	bo[x][y][stackSize-1]=0;
	else return 0;
	return 1;
}
