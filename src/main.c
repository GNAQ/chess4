#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "cboard/cboard.h"
#include "natsu/natsu.h"

void Show_Rules()
{
	system("cls");
	puts("��������Ϸ����");
	puts("��ô����˭д���������Ҳ���д�ˡ�");
	
	puts("�� [1] �����ϸ�ҳ�档");
	
	// Get_single_key_input("1");
	return;
}

void Show_Welcome_Info()
{
	system("cls");
	puts("��ӭ����������");
	puts("�� [1] ����˫��ģʽ");
	puts("�� [2] ��������˶�սģʽ");
	puts("�� [0] �鿴��Ϸ����");
	puts("----------------------------");
	// TODO �˻�ģ��ĳ�ʼ���
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

// ��ʼ�Ļ�ӭҳ��
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
			goto fnt; // ��ƫҪ�� goto��
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