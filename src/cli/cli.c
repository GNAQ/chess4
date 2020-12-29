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
	
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("▼");
		else
			printf("--");
	}
	printf("-\n");
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
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("▲");
		else
			printf("--");
	}
	printf("-\n");
	
	printf("--------------------\n");
	puts("按 [J] [K] 键切换落子位置向左/向右，按 [B] 键落子。");
	printf("现在是 %s 落子。\n", (goer == 1) ? bd->userA : bd->userB);
	
	return;
}


void Show_hisA(Board* bd, HisA *his, int cnt_pos)
{
	system("cls");
	int i, j, ii, jj, cursorpos;
	
	printf("---------------------------------\n");
	printf("|    %10s vs %-10s    |\n", his->userA, his->userB);
	printf("---------------------------------\n");
	if (his->winner == -1)
		printf("|              平局              |\n");
	else
		printf("|        %10s 胜利        |\n", 
			   (his->winner == 1) ? his->userA : his->userB);
	printf("---------------------------------\n");
	printf("\n\n");
	
	cursorpos = his->posx[cnt_pos];
	
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("▼");
		else
			printf("--");
	}
	printf("-\n");
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
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("▲");
		else
			printf("--");
	}
	printf("-\n");
	
	printf("现在是第 [%d] 步。\n", cnt_pos);
	printf("%s 在 ( %d , %d ) 落子。\n", 
		   (cnt_pos % 2 == 1) ? his->userA : his->userB, 
		   his->posx[cnt_pos], his->posy[cnt_pos]);
	
	printf("--------------------\n");
	puts("按 [J] [K] 键向前/后一步。按 [Q] 退出。\n");
	return;
}

int Show_his_list(int sel)
{
	system("cls");
	
	char str[50];
	int i = 0;
	__Sys_time *systm;
	time_t std_fmt_systm;
	
	FILE *fplist = fopen("Histories/HList.txt","r");
	if (fplist == NULL)
	{
		puts("文件不存在！程序退出。");
		system("pause"); exit(4);
	}
	
	printf("------------------------------\n");
	printf("|      选择历史记录：        |\n");
	printf("------------------------------\n");
	
	while (fgets(str, 50, fplist) != NULL)
	{
		i++;
		sscanf(str, "log_%lld.c4log", &std_fmt_systm);
		systm = gmtime(&std_fmt_systm);
		
		printf("[A类记录] 游戏时间：%d/%d/%d %02d:%02d:%02d (英国 0 时区)",
			systm->tm_year + 1900, systm->tm_mon + 1, systm->tm_mday,
			systm->tm_hour, systm->tm_min, systm->tm_sec);
		
		if (i == sel) 
			printf("                 [当前选中]\n");
		else 
			printf("\n");
		printf("----------------------------------------------------------\n");
	}
	
	printf("\n\n按 [J] [K] 上/下选择。按 [B] 确定。按 [Q] 退出。\n");
	printf("------------------------------\n");
	return i;
}