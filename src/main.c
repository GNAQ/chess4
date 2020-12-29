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
	puts("�� [2] �鿴�˺���Ϣ");
	puts("�� [0] �鿴��Ϸ����");
	puts("----------------------------");
	return;
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

void Test_shouboard()
{
	CreateResult *res;
	res = Create_chessboard(7, 7, "GNAQ", "dkw", 112, 113);
	
	res->bd.mat[4][4]=2;
	res->bd.mat[6][5]=1;
	res->bd.mat[7][1]=2;
	res->bd.mat[1][3]=1;
	
	Show_board(&(res->bd), 3, 2);
	
	printf("SHOW BOARD TEST END HERE!\n");
	system("pause");
	system("cls");
	return;
}

int main()
{
	Change_window_size(150,50);
	
	Lib_check();
	
	Welcome();
	
	Test_shouboard();
	
	puts("TESTS END HERE");
	system("pause");
	return 0;
}