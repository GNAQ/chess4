#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void Show_Rules()
{
	system("cls");
	puts("��������Ϸ����");
	puts("��ô����˭д���������Ҳ���д�ˡ�");
	
	puts("�� [1] �����ϸ�ҳ�档");
	// TODO ������������ɷ�����ʽ�ģ�ר�ſ�����д�ã����Դ����ڴ��ַ����ַ��������ַ�������ʽ�����ش����
	char inp = 0;
	while (inp != '1') 
		inp = getchar();
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
			goto fnt;
		case '1':
			
			break;
		case '2':
			
			break;
	}
}

// �ı䴰�ڴ�С h by w
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