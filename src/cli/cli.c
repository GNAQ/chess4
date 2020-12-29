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
	
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("��");
		else
			printf("--");
	}
	printf("-\n");
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
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("��");
		else
			printf("--");
	}
	printf("-\n");
	
	printf("--------------------\n");
	puts("�� [J] [K] ���л�����λ������/���ң��� [B] �����ӡ�");
	printf("������ %s ���ӡ�\n", (goer == 1) ? bd->userA : bd->userB);
	
	return;
}


void Show_hisA(Board* bd, HisA *his, int cnt_pos)
{
	system("cls");
	int i, j, ii, jj, cursorpos;
	
	printf("---------------------------------\n");
	printf("|    %10s vs %-10s    |\n", his->userA, his->userB);
	printf("---------------------------------\n");
	if (his->winner == -1)
		printf("|              ƽ��              |\n");
	else
		printf("|        %10s ʤ��        |\n", 
			   (his->winner == 1) ? his->userA : his->userB);
	printf("---------------------------------\n");
	printf("\n\n");
	
	cursorpos = his->posx[cnt_pos];
	
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("��");
		else
			printf("--");
	}
	printf("-\n");
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
	putchar('-');
	for (i = 1; i <= bd->width; i++)
	{
		if (i == cursorpos)
			printf("��");
		else
			printf("--");
	}
	printf("-\n");
	
	printf("�����ǵ� [%d] ����\n", cnt_pos);
	printf("%s �� ( %d , %d ) ���ӡ�\n", 
		   (cnt_pos % 2 == 1) ? his->userA : his->userB, 
		   his->posx[cnt_pos], his->posy[cnt_pos]);
	
	printf("--------------------\n");
	puts("�� [J] [K] ����ǰ/��һ������ [Q] �˳���\n");
	return;
}

int Show_his_list(int sel)
{
	system("cls");
	
	char str[50];
	int i = 0;
	__Sys_time *systm;
	time_t std_fmt_systm;
	
	FILE *fplist = fopen("Histories/HList.txt","r");
	if (fplist == NULL)
	{
		puts("�ļ������ڣ������˳���");
		system("pause"); exit(4);
	}
	
	printf("------------------------------\n");
	printf("|      ѡ����ʷ��¼��        |\n");
	printf("------------------------------\n");
	
	while (fgets(str, 50, fplist) != NULL)
	{
		i++;
		sscanf(str, "log_%lld.c4log", &std_fmt_systm);
		systm = gmtime(&std_fmt_systm);
		
		printf("[A���¼] ��Ϸʱ�䣺%d/%d/%d %02d:%02d:%02d (Ӣ�� 0 ʱ��)",
			systm->tm_year + 1900, systm->tm_mon + 1, systm->tm_mday,
			systm->tm_hour, systm->tm_min, systm->tm_sec);
		
		if (i == sel) 
			printf("                 [��ǰѡ��]\n");
		else 
			printf("\n");
		printf("----------------------------------------------------------\n");
	}
	
	printf("\n\n�� [J] [K] ��/��ѡ�񡣰� [B] ȷ������ [Q] �˳���\n");
	printf("------------------------------\n");
	return i;
}