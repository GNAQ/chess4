#include "cboard.h"

void HelloCBoard()
{
	HelloNatsu();
	printf("Hello CBoard!\n");
	system("pause");
	return;
}

CreateResult Create_chessboard(int height, int width)
{
	int i;
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
	
	result.result = 1;
	return result;
}
