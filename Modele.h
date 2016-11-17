#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
typedef int *** board;
typedef int ** grid;
typedef int * stack;


int max(int n1, int n2)
{
	if (n1>n2) return n1;
	return n2;
}

board create_board(int n)
{
	int i=0,j=0,k=0;
	board mainBoard=(board)calloc(n,sizeof(long int));
	for (i=0;i<n;i=i+1)
	{
		grid gridAdress=(grid)calloc(n,sizeof(char *));
		mainBoard[i]=gridAdress;
		for (j=0;j<n;j=j+1)
		{
			stack stackAdress=calloc(n+1,sizeof(char));
			mainBoard[i][j]=stackAdress;
			for (k=0;k<n;k=k+1)	stackAdress[k]=' ';
			stackAdress[n]='\1';
		}		
	}
	return (board) mainBoard;
}

grid create_stackgrid(int n)
{
	int i=0,j=0;
	grid mainGrid=(int **)calloc(n,sizeof(long int));
	for (i=0;i<n;i=i+1)
	{
		int * gridAdress=calloc(n,sizeof(int));
		for (j=0;j<n;j=j+1)
		{
			gridAdress[j]=0;
		}
		mainGrid[i]=gridAdress;
	}
	return (grid) mainGrid;
}


int add_item(int item, board bo, int x, int y, int stackSize)
{
	if (bo[x][y][stackSize]=='\1')
	{
		int i=0;
		stack stackAdress=calloc(2*stackSize+1,sizeof(int));
		
		for (i=0;i<stackSize;i=i+1)
			stackAdress[i]=bo[x][y][i];
		for (i=stackSize;i<2*stackSize;i=i+1)
			stackAdress[i]=0;
		stackAdress[2*stackSize]='\1';
		bo[x][y]=stackAdress;
	}
	bo[x][y][stackSize]=item;
	return 1;
}

int remove_item(board bo, int x, int y, int stackSize)
{
	if (stackSize>0)
	bo[x][y][stackSize-1]=0;
	else return 0;
	return 1;
}

int display_Board(board bo, int n, int x, int y, grid stacks)
{
	int i=0,j=0;
	for (i=0;i<=4*n;i=i+1) printf("-");
	printf("\n");
	for (i=0;i<n;i=i+1)
	{
		printf("|");
		for (j=0;j<n;j=j+1)
		{
			if (i==x && j==y) printf("+++|");
			else printf("   |");
		}
		printf("\n|");
		for (j=0;j<n;j=j+1)
		{
			if (i==x && j==y) printf("+%c+|",bo[i][j][max(stacks[i][j]-1,0)]);
			else printf(" %c |",bo[i][j][max(stacks[i][j]-1,0)]);
		}
		printf("\n|");
		for (j=0;j<n;j=j+1)
		{
			if (i==x && j==y) printf("+++|");
			else printf("   |");
		}
		printf("\n");
		for (i=0;i<=4*n;i=i+1) printf("-");
		printf("\n");
	}
	return 1;
}
