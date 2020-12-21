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
