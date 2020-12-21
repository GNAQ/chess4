#include "cboard.h"

void HelloCBoard()
{
	HelloNatsu();
	printf("Hello CBoard!\n");
	system("pause");
	return;
}

CreateResult Create_chessboard(int height, int width, char *usrA, char *usrB, int idA, int idB)
{
	int i, j, ii, jj;
	CreateResult result;
	
	result.bd.height = height;
	result.bd.width = width;
	result.bd.mat = calloc(height + 2, sizeof(int *));
	
	if (result.bd.mat == NULL)
	{
		result.result = -1;
		return result;
	}
	
	for (i = 0; i <= height; i++)
	{
		result.bd.mat[i] = calloc(width + 2, sizeof(int));
		if (result.bd.mat[i] == NULL)
		{
			result.result = -1;
			return result;
		}
	}
	
	for (i = 0; i <= height; i++)
		for (j = 0; j <= width; j++)
			result.bd.mat[i][j] = 0;
	strcpy(result.bd.userA, usrA);
	strcpy(result.bd.userB, usrB);
	result.bd.idA = idA;
	result.bd.idB = idB;
	result.bd.winner = 0;
	
	
	result.result = 1;
	return result;
}

// REVIEW
int Finish(Board *bd)
{
	int i, j, h, w, ii, jj;
	h = bd->height;
	w = bd->width;
	
	// ----
	for (i = 1; i <= h; i++)
		for (j = 1; j <= w - 3; j++) 
			if (bd->mat[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (bd->mat[i][j + ii] != bd->mat[i][j])
						ok = 0;
				if (ok == 1) 
					return bd->mat[i][j];
			}
	// ||||
	for (i = 1; i <= w; i++)
		for (j = 1; j <= h - 3; j++) 
			if (bd->mat[j][i] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (bd->mat[j + ii][i] != bd->mat[j][i])
						ok = 0;
				if (ok == 1) 
					return bd->mat[j][i];
			}
	// ////
	for (i = 1; i <= h - 3; i++) 
		for (j = 4; j <= w; j++)
			if (bd->mat[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (bd->mat[i + ii][j - ii] != bd->mat[i][j])
						ok = 0;
				if (ok == 1) 
					return bd->mat[i][j];
			}
	// \\\\ /
	for (i = 1; i <= h - 3; i++) 
		for (j = 1; j <= w - 3; j++)
			if (bd->mat[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (bd->mat[i + ii][j + ii] != bd->mat[i][j])
						ok = 0;
				if (ok == 1) 
					return bd->mat[i][j];
			}
	
	return 0;
}

void Add_beam(Board *bd, int xpos, int color)
{
	// TODO
}