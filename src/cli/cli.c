#include "cli.h"

void HelloCli()
{
	HelloNatsu();
	puts("Hello Cli!");
	system("pause");
	return;
}

void Show_rules()
{
	system("cls");
	puts("四子棋游戏规则：");
	puts("四子棋的棋盘是垂直摆放。");
	puts("两名玩者轮流每次把一只棋子放进棋盘任何未全满的一行中，棋子会占据一行中最底未被占据的位置。");
	puts("两名玩者任何一方先以四只棋子在横，竖或斜方向联成一条直线，便可获胜，游戏亦结束。");
	puts("假如棋盘已完全被棋子填满，但仍未有任何一方成功把四只棋子成一直线，则成为和局。");
	puts("按 [1] 返回上个页面。");
	
	Get_single_key_input("1");
	return;
}

void Start_2p_game()
{
	// TODO
}

void Show_board(Board *bd, int cursorpos, int goer) // ○●
{
	system("cls");
	int i, j, ii, jj;
	
	printf("---------------------------------\n");
	printf("|    %10s vs %-10s    |\n", bd->userA, bd->userB);
	printf("---------------------------------\n");
	printf("\n\n");
	
	putchar(' ');
	for (i = 1; i <= bd->width; i++)
	{
		if (i != cursorpos) printf("  ");
		else printf("↓");
	}
	printf("\n\n");
	
	for (i = 1; i <= bd->width + 1; i++)
		printf("--");
	putchar('\n');
	for (i = 1; i <= bd->height; i++)
	{
		putchar('|');
		for (j = 1; j <= bd->width; j++)
		{
			switch (bd->mat[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("○");
				break;
			case 2:
				printf("●");
				break;
			}
		}
		putchar('|'); putchar('\n');
	}
	for (i = 1; i <= bd->width + 1; i++)
		printf("--");
	putchar('\n');
	
	printf("--------------------\n");
	puts("按 [J] [K] 键切换落子位置向左/向右，按 [B] 键落子。");
	printf("现在是 %s 落子。\n", (goer == 1) ? bd->userA : bd->userB);
	
	// TODO 显示账号信息和对弈信息
	printf("----TODO----\n\n");
	return;
}