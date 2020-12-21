#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "cboard/cboard.h"
#include "natsu/natsu.h"
#include "cli/cli.h"

void Show_Rules()
{
	system("cls");
	puts("四子棋游戏规则：");
	puts("四子棋的棋盘是垂直摆放。\
	两名玩者轮流每次把一只棋子放进棋盘\
	任何未全满的一行中，棋子会占据一行中最底未被占据的位置。两名玩\
	者任何一方先以四只棋子在横，竖或斜方向联成一条直线，便可获胜，\
	游戏亦结束。假如棋盘已完全被棋子填满，但仍未有任何一方成功把四\
	只棋子成一直线，则成为和局。");
	
	puts("按 [1] 返回上个页面。");
	
	Get_single_key_input("1");
	return;
}

void Show_Welcome_Info()
{
	system("cls");
	puts("欢迎游玩四子棋");
	puts("按 [1] 进入双人模式");
	puts("按 [2] 进入机器人对战模式");
	puts("按 [0] 查看游戏规则");
	puts("----------------------------");
	// TODO 账户模块的初始入口
	// Get_Account_Info();
	return;
}

// 初始的欢迎页面
void Welcome()
{
	fnt:
	Show_Welcome_Info();
	
	int keyid = Get_single_key_input("012");
	switch (keyid)
	{
		case 0:
			Show_Rules();
			goto fnt; // 我偏要用 goto。
		case 1:
			
			break;
		case 2:
			
			break;
	}
}

void Lib_check()
{
	printf("------------Library Check Starts------------\n");
	HelloNatsu();
	HelloCBoard();
	HelloCli();
	system("cls");
}

int main()
{
	Change_window_size(150,50);
	
	Lib_check();
	
	Welcome();
	
	
	puts("TESTS END HERE");
	system("pause");
	
}