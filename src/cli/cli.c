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
	puts("��������Ϸ����");
	puts("������������Ǵ�ֱ�ڷš�");
	puts("������������ÿ�ΰ�һֻ���ӷŽ������κ�δȫ����һ���У����ӻ�ռ��һ�������δ��ռ�ݵ�λ�á�");
	puts("���������κ�һ��������ֻ�����ںᣬ����б��������һ��ֱ�ߣ���ɻ�ʤ����Ϸ�������");
	puts("������������ȫ����������������δ���κ�һ���ɹ�����ֻ���ӳ�һֱ�ߣ����Ϊ�;֡�");
	puts("�� [1] �����ϸ�ҳ�档");
	
	Get_single_key_input("1");
	return;
}

void Start_2p_game()
{
	// TODO
}

void Show_board(Board *bd, int cursorpos, int goer) // ���
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
		else printf("��");
	}
	printf("\n\n");
	
	for (i = 1; i <= bd->width + 1; i++)
		printf("--");
	putchar('\n');
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
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			}
		}
		putchar('|'); putchar('\n');
	}
	for (i = 1; i <= bd->width + 1; i++)
		printf("--");
	putchar('\n');
	
	printf("--------------------\n");
	puts("�� [J] [K] ���л�����λ������/���ң��� [B] �����ӡ�");
	printf("������ %s ���ӡ�\n", (goer == 1) ? bd->userA : bd->userB);
	
	// TODO ��ʾ�˺���Ϣ�Ͷ�����Ϣ
	printf("----TODO----\n\n");
	return;
}