#include "natsu.h"

void ReadInt(int *x)
{
	(*x) = 0; int k = 1; char ch = 0;
	while (ch < '0' || ch > '9') 
	{ 
		ch = getchar();
		if (ch == '-') k = -1;
	}
	while (ch >= '0' && ch <= '9')
	{
		(*x) = (*x) * 10 + ch - '0';
		ch = getchar();
	}
	(*x) *= k;
}

int Get_single_key_input(char *req)
{
	int reqlen = strlen(req);
	int i, pos_default = -1;
	char c;

	for (i = 0; i < reqlen; i++)
		if (req[i] == '_')
			pos_default = i;

	while (c = getch())
	{
		for (i = 0; i < reqlen; i++)
			if ((c == req[i]) && (i != pos_default))
				return i;
		if (pos_default != -1)
			return pos_default;
	}
	return -1;
}

// 改变窗口大小 h by w
void Change_window_size(int height, int width)
{
	char commands[30];
	sprintf(commands, "mode con cols=%d lines=%d", height, width);
	system(commands);
	return;
}

// 输出 Hello Natsu 测试
void HelloNatsu(void)
{
	puts("Hello Natsu!");
	system("pause");
	return;
}

void Check_file_dir(void)
{
	system("md Histories 2>nul >nul");
	system("if not exist Histories\\HList.txt echo a 2>Histories\\HList.txt");
	system("md Histories\\Logs 2>nul >nul");
	system("cls");
	return;
}

// REVIEW
FileLL* Add_filell(FileLL *last, FILE* addfp)
{
	FileLL* add = calloc(1, sizeof(FileLL));
	if (add == NULL)
	{
		puts("程序内存不足！即将退出。");
		system("pause");
		exit(3);
	}
	
	add->prev = last;
	last->next = add;
	add->next = NULL;
	add->fp = addfp;
	return add;
}

void Save_his(HisA* his)
{
	FILE *fplist = fopen("Histories/HList.txt","a");
	if (fplist == NULL)
	{
		puts("文件不存在！程序退出。");
		system("pause"); exit(4);
	}
	fprintf(fplist, "log_%lld.c4log\n", his->std_fmt_time);
	fclose(fplist);
	
	char fname[30];
	sprintf(fname, "Histories/Logs/log_%lld.c4log", his->std_fmt_time);
	
	FILE *fphis = fopen(fname, "w");
	if (fphis == NULL)
	{
		puts("文件不存在！程序退出。");
		system("pause");
		exit(4);
	}
	
	fprintf(fphis, "%lld\n", his->std_fmt_time);
	fprintf(fphis, "%d %d %d\n",
			his->game_time->tm_year + 1900, his->game_time->tm_mon + 1, 
			his->game_time->tm_mday);
	fprintf(fphis, "%d %d %d\n",
			his->game_time->tm_hour, his->game_time->tm_min, 
			his->game_time->tm_sec);
	fprintf(fphis, "%s %s\n", his->userA, his->userB);
	fprintf(fphis, "%d %d\n", his->height, his->width);
	fprintf(fphis, "%d %d\n", his->winner, his->tot_steps);
	int i, j = his->tot_steps;
	for (i = 1; i <= j; i++)
		fprintf(fphis, "%d %d\n", his->posx[i], his->posy[i]);
	fclose(fphis);
	return;
}

FileLL* Init_filell(void)
{
	FileLL* ret = calloc(1, sizeof(FileLL));
	if (ret == NULL)
	{
		puts("程序内存不足！即将退出。");
		system("pause");
		exit(3);
	}
	
	ret->next = ret->prev = NULL;
	ret->fp = NULL;
	return ret;
}

void Read_his(FileLL *logid, HisA *his)
{
	int i, j;
	fscanf(logid->fp, "%lld%d%d%d%d%d%d", 
		&(his->std_fmt_time), &(his->game_time->tm_year), &(his->game_time->tm_mon),
		&(his->game_time->tm_mday), &(his->game_time->tm_hour), &(his->game_time->tm_min),
		&(his->game_time->tm_sec));
	his->game_time->tm_year -= 1900;
	his->game_time->tm_mon -= 1;
	fscanf(logid->fp, "%s%s", his->userA, his->userB);
	fscanf(logid->fp, "%d%d%d%d",
		&(his->height), &(his->width), &(his->winner), &(his->tot_steps));
	j = his->tot_steps;
	for (i = 1; i <= j; i++)
		fscanf(logid->fp, "%d%d", &(his->posx[i]), &(his->posy[i]));
	return;
}

FileLL* Resolute_filelog(FileLL *head)
{
	
}

void Destroy_filelog(FileLL *head)
{
	if (head->next != NULL) Destroy_filelog(head->next);
	free(head);
	return;
}