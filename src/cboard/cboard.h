// 创建一个棋盘，并处理棋盘操作
// “核心交互库”。

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "../natsu/natsu.h"

void HelloCBoard();

struct _HistoryA
{
	// TODO
};
typedef struct _HistoryA HisA;

struct _Board
{
	// 盘面
	int **mat;
	int height, width;
	// 对弈
	char *userA, *userB; // 用户名
	int idA, idB; // 用户 Hash
	int winner; // .. 0 / 1 / 2 / -1[平局]
	// 历史
	// TODO
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
CreateResult Create_chessboard(int height, int width, char *usrA, char *usrB, int idA, int idB);

// 添加一个子
void Add_beam(Board *bd, int xpos, int color);

// 判断是否结棋
int Finish(Board *bd);

// TODO 悔棋 
void Rollback(Board *bd);

// **查看对弈历史是 CLI 该做的事情。**