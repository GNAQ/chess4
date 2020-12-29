#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "cboard/cboard.h"
#include "natsu/natsu.h"
#include "cli/cli.h"

void Show_Welcome_Info()
{
	system("cls");
	puts("欢迎游玩四子棋");
	puts("按 [1] 进入双人模式");
	puts("按 [2] 查看对弈历史记录");
	puts("按 [0] 查看游戏规则");
	puts("----------------------------");
	return;
}

int Hold_round(Board *bd, int cursorpos, int goer)
{
	int call_back = 0;
	while (1)
	{	
		Show_board(bd, cursorpos, goer);
		call_back = Get_single_key_input("jkb");
		
		switch (call_back)
		{
		case 0:
			if (cursorpos > 1) 
				cursorpos--;
			break;
		case 1:
			if (cursorpos < bd->width)
				cursorpos++;
			break;
		case 2:
			if (Add_beam(bd, cursorpos, goer) == 1)
				return cursorpos;
			break;
		}
	}
}

void Create_2p_game()
{
	int w, h, i, j;
	int cursorpos, goer;
	int win_status;
	int call_back;
	
	game_2p_start:
	
	w = h = -1;
	cursorpos = 1; goer = 0;
	win_status = 0;
	
	system("cls");
	puts("请您选定棋盘大小。最小宽高：5×5 最大宽高：22×22");
	
	printf("棋盘宽度：");
	scanf("%d", &w);
	while (w < 5 || w > 22)
	{
		printf("输入不合法！\n棋盘宽度：");
		ReadInt(&w);
	}
	printf("棋盘高度：");
	scanf("%d", &h);
	while (h < 5 || h > 22)
	{
		printf("输入不合法！\n棋盘高度：");
		ReadInt(&h);
	}
	
	CreateResult *res;
	res = Create_chessboard(h, w, "Player1", "Player2", 1001, 1002);
	
	if (res->result != 1)
	{
		puts("创建棋盘时遇到错误，程序退出！");
		system("pause");
		exit(1);
	}
	
	puts("对局开始！");
	system("pause");
	
	while (win_status == 0)
	{
		goer ++;
		if (goer == 3) goer = 1;
		
		cursorpos = Hold_round(&(res->bd), cursorpos, goer);
		
		win_status = Finish(&(res->bd));
		if (res->bd.his->tot_steps == res->bd.height * res->bd.width)
		{
			win_status = -1;
			break;
		}
	}
	
	Show_board(&(res->bd), cursorpos, goer);
	if (win_status == -1)
		printf("游戏结束！平局。\n");
	else
		printf("游戏结束！胜者是 %s", (goer == 1) ? res->bd.userA : res->bd.userB);
	
	res->bd.his->winner = win_status;
	
	puts("您要保存本次对局的历史记录吗？按 [Y] 保存，按 [N] 不保存。");
	call_back = Get_single_key_input("yn");
	if (call_back == 0)
		Save_his(res->bd.his);
	
	Destroy_chessboard(res);
	
	puts("按 [1] 退出。按 [4] 再来一局。");
	call_back = Get_single_key_input("14");
	if (call_back == 0) return;
	else goto game_2p_start;
}

void Look_up_his()
{
	// TODO
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
			Show_rules();
			goto fnt; // 我偏要用 goto。
		case 1:
			Create_2p_game();
			break;
		case 2:
			
			break;
	}
}

// ANCHOR 下面是检查

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
	Change_window_size(110,40);
	Check_file_dir();
	
	Lib_check();
	
	Welcome();
	
	puts("TESTS END HERE");
	system("pause");
	return 0;
}