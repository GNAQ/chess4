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
	puts("��ӭ����������");
	puts("�� [1] ����˫��ģʽ");
	puts("�� [2] �鿴������ʷ��¼");
	puts("�� [0] �鿴��Ϸ����");
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
	puts("����ѡ�����̴�С����С��ߣ�5��5 ����ߣ�22��22");
	
	printf("���̿�ȣ�");
	scanf("%d", &w);
	while (w < 5 || w > 22)
	{
		printf("���벻�Ϸ���\n���̿�ȣ�");
		ReadInt(&w);
	}
	printf("���̸߶ȣ�");
	scanf("%d", &h);
	while (h < 5 || h > 22)
	{
		printf("���벻�Ϸ���\n���̸߶ȣ�");
		ReadInt(&h);
	}
	
	CreateResult *res;
	res = Create_chessboard(h, w, "Player1", "Player2", 1001, 1002);
	
	if (res->result != 1)
	{
		puts("��������ʱ�������󣬳����˳���");
		system("pause");
		exit(1);
	}
	
	puts("�Ծֿ�ʼ��");
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
		printf("��Ϸ������ƽ�֡�\n");
	else
		printf("��Ϸ������ʤ���� %s", (goer == 1) ? res->bd.userA : res->bd.userB);
	
	res->bd.his->winner = win_status;
	
	puts("��Ҫ���汾�ζԾֵ���ʷ��¼�𣿰� [Y] ���棬�� [N] �����档");
	call_back = Get_single_key_input("yn");
	if (call_back == 0)
		Save_his(res->bd.his);
	
	Destroy_chessboard(res);
	
	puts("�� [1] �˳����� [4] ����һ�֡�");
	call_back = Get_single_key_input("14");
	if (call_back == 0) return;
	else goto game_2p_start;
}

void Look_up_his()
{
	// TODO
}

// ��ʼ�Ļ�ӭҳ��
void Welcome()
{
	fnt:
	Show_Welcome_Info();
	
	int keyid = Get_single_key_input("012");
	switch (keyid)
	{
		case 0:
			Show_rules();
			goto fnt; // ��ƫҪ�� goto��
		case 1:
			Create_2p_game();
			break;
		case 2:
			
			break;
	}
}

// ANCHOR �����Ǽ��

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