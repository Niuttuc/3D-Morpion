#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include "Modele.h"

int main()
{
	display_Board(create_board(5), 5, 3, 3, create_stackgrid(5));
	return 0;
}
