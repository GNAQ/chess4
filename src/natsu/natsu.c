#include "natsu.h"

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
void HelloNatsu()
{
	puts("Hello Natsu!");
	system("pause");
	return;
}

