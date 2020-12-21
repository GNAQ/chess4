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
	puts("��������Ϸ����");
	puts("������������Ǵ�ֱ�ڷš�\
	������������ÿ�ΰ�һֻ���ӷŽ�����\
	�κ�δȫ����һ���У����ӻ�ռ��һ�������δ��ռ�ݵ�λ�á�������\
	���κ�һ��������ֻ�����ںᣬ����б��������һ��ֱ�ߣ���ɻ�ʤ��\
	��Ϸ�������������������ȫ����������������δ���κ�һ���ɹ�����\
	ֻ���ӳ�һֱ�ߣ����Ϊ�;֡�");
	
	puts("�� [1] �����ϸ�ҳ�档");
	
	Get_single_key_input("1");
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
			Show_Rules();
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

int main()
{
	Change_window_size(150,50);
	
	Lib_check();
	
	Welcome();
	
	
	puts("TESTS END HERE");
	system("pause");
	
}