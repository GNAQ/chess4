#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "cboard/cboard.h"
#include "natsu/natsu.h"

void Show_Rules()
{
	system("cls");
	puts("四子棋游戏规则：");
	puts("那么长，谁写啊，反正我不想写了。");
	
	puts("按 [1] 返回上个页面。");
	
	// Get_single_key_input("1");
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
	
	/*
	int keyid = Get_single_key_input("012");
	switch (keyid)
	{
	case 0:
		Show_Rules();
		break;
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		break;
	} */
}

// 初始的欢迎页面
void Welcome()
{
	fnt:
	Show_Welcome_Info();
	
	char inp = 0;
	while (inp != '0' && inp != '1' && inp != '2')
		inp=getchar();
	switch(inp)
	{
		case '0':
			Show_Rules();
			goto fnt; // 我偏要用 goto。
		case '1':
			
			break;
		case '2':
			
			break;
	}
}

void Lib_check()
{
	// HelloNatsu();
	HelloCBoard();
}

int main()
{
	// Change_window_size(150,50);
	// Welcome();
	Lib_check();
	
	
	system("cls");
	puts("TESTS END HERE");
	system("pause");
	
}