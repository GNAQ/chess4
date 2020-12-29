#include "cboard.h"

void HelloCBoard()
{
	HelloNatsu();
	printf("Hello CBoard!\n");
	system("pause");
	return;
}

CreateResult* Create_chessboard(int height, int width, char *usrA, char *usrB, int idA, int idB)
{
	int i, j, ii, jj;
	CreateResult *result = calloc(1, sizeof(CreateResult));
	
	if (result == NULL)
	{
		printf("无法获取最低所需的内存进行游戏！\n程序退出。\n");
		system("pause");
		exit(2);
	}
	
	CreateHisA *chis = Create_HisA(1);
	if (chis->result != 1)
	{
		result->result = -1;
		return result;
	}
	result->bd.his = &(chis->his);
	
	result->bd.height = height;
	result->bd.width = width;
	result->bd.his->height = height;
	result->bd.his->width = width;
	result->bd.mat = calloc(height + 2, sizeof(int *));
	
	if (result->bd.mat == NULL)
	{
		result->result = -1;
		return result;
	}
	
	for (i = 0; i <= height + 1; i++)
	{
		result->bd.mat[i] = calloc(width + 2, sizeof(int));
		if (result->bd.mat[i] == NULL)
		{
			result->result = -1;
			return result;
		}
	}
	
	result->bd.userA = calloc(10, sizeof(char));
	result->bd.userB = calloc(10, sizeof(char));
	if (result->bd.userA == NULL || result->bd.userB == NULL)
	{
		result->result = -1;
		return result;
	}
	
	for (i = 0; i <= height; i++)
		for (j = 0; j <= width; j++)
			result->bd.mat[i][j] = 0;
	
	strcpy(result->bd.userA, usrA);
	strcpy(result->bd.his->userA, usrA);
	strcpy(result->bd.userB, usrB);
	strcpy(result->bd.his->userB, usrB);
	result->bd.idA = idA;
	result->bd.idB = idB;
	result->bd.winner = 0;
	
	result->result = 1;
	return result;
}

int Finish(Board *bd)
{
	int i, j, h, w, ii, jj;
	HisA *his = bd->his;
	int **ma = bd->mat;
	h = bd->height;
	w = bd->width;
	
	// ----
	for (i = 1; i <= h; i++)
		for (j = 1; j <= w - 3; j++) 
			if (ma[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (ma[i][j + ii] != ma[i][j])
						ok = 0;
				if (ok == 1) 
				{
					his->winner = ma[i][j];
					return ma[i][j];
				}
			}
	// ||||
	for (i = 1; i <= w; i++)
		for (j = 1; j <= h - 3; j++) 
			if (ma[j][i] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (ma[j + ii][i] != ma[j][i])
						ok = 0;
				if (ok == 1) 
				{
					his->winner = ma[j][i];
					return ma[j][i];
				}
			}
	// ////
	for (i = 1; i <= h - 3; i++) 
		for (j = 4; j <= w; j++)
			if (ma[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (ma[i + ii][j - ii] != ma[i][j])
						ok = 0;
				if (ok == 1) 
				{
					his->winner = ma[i][j];
					return ma[i][j];
				}
			}
	// \\\\ /
	for (i = 1; i <= h - 3; i++) 
		for (j = 1; j <= w - 3; j++)
			if (ma[i][j] != 0)
			{
				int ok = 1;
				for (ii = 1; ii <= 3; ii++)
					if (ma[i + ii][j + ii] != ma[i][j])
						ok = 0;
				if (ok == 1) 
				{
					his->winner = ma[i][j];
					return ma[i][j];
				}
			}
	
	return 0;
}

int Add_beam(Board *bd, int xpos, int color)
{
	HisA *his = bd->his;
	if (bd->mat[1][xpos] != 0)
		return 0;
	
	int ypos = bd->height;
	while (bd->mat[ypos][xpos] != 0)
		ypos--;
	
	bd->mat[ypos][xpos] = color;
	
	his->tot_steps++;
	int tot = his->tot_steps;
	his->posx[tot] = xpos;
	his->posy[tot] = ypos;
	return 1;
}

void Destroy_chessboard(CreateResult *result)
{
	Destroy_HisA(result->bd.his);
	int i, j;
	free(result->bd.userA);
	free(result->bd.userB);
	for (i = 0; i <= result->bd.height + 1; i++)
		free(result->bd.mat[i]);
	free(result->bd.mat);
	free(result);
	return;
}

CreateHisA* Create_HisA(int write_cur_time)
{
	CreateHisA* ret = calloc(1, sizeof(CreateHisA));
	
	if (ret == NULL)
	{
		printf("无法获取最低所需的内存进行游戏！\n程序退出。\n");
		system("pause");
		exit(2);
	}
	
	if (write_cur_time == 0)  
		ret->his.game_time = NULL;
	else
	{
		time_t std_format_time;
		time(&std_format_time);
		ret->his.game_time = gmtime(&std_format_time);
		ret->his.std_fmt_time = std_format_time;
	}
	
	ret->his.userA = calloc(10, sizeof(char));
	ret->his.userB = calloc(10, sizeof(char));
	if (ret->his.userA == NULL || ret->his.userB == NULL)
	{
		ret->result = -1;
		return ret;
	}
	
	ret->his.posx = calloc(500, sizeof(int));
	ret->his.posy = calloc(500, sizeof(int));
	
	if (ret->his.posx == NULL || ret->his.posy == NULL)
	{
		ret->result = -1;
		return ret;
	}
	
	ret->his.tot_steps = 0;
	ret->his.winner = 0;
	
	ret->result = 1;
	return ret;
}

void Destroy_HisA(HisA *his)
{
	free(his->posx);
	free(his->posy);
	free(his->userB);
	free(his->userA);
	return;
}