// 创建一个棋盘，并处理棋盘操作
// “核心交互库”。

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "../natsu/natsu.h"

void HelloCBoard();

struct _Board
{
	int **mat;
	int height, width;
};
typedef struct _Board Board;

// 创建的结果
struct _CreateResult
{
	// 创建成功返回 1
	// 内存空间不足返回 -1
	int result;
	Board bd;
};
typedef struct _CreateResult CreateResult;

// 创建一个棋盘 h by w
CreateResult Create_chessboard(int height, int width);