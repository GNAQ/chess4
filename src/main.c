#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void Show_Rules()
{
	system("cls");
	puts("四子棋游戏规则：");
	puts("那么长，谁写啊，反正我不想写了。");
	
	puts("按 [1] 返回上个页面。");
	// TODO 把这个东西做成非阻塞式的，专门开个库写好，可以传入期待字符的字符集（以字符串的形式），回传编号
	char inp = 0;
	while (inp != '1') 
		inp = getchar();
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
			goto fnt;
		case '1':
			
			break;
		case '2':
			
			break;
	}
}

// 改变窗口大小 h by w
void Change_Window_Size(int height, int width)
{
	char commands[30];
	sprintf(commands, "mode con cols=%d lines=%d", height, width);
	system(commands);
	return;
}

int main()
{
	Change_Window_Size(150,50);
	Welcome();
	
	system("cls");
	puts("TESTS END HERE");
	system("pause");
	
}