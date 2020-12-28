// 创建一个棋盘，并处理棋盘操作
// “核心交互库”。

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "../natsu/natsu.h"

void HelloCBoard();

// 创建一个棋盘 h by w
CreateResult* Create_chessboard(int height, int width, char *usrA, char *usrB, int idA, int idB);

void Destroy_chessboard(Board *bd);

// 添加一个子 [1 成功 || -1 满格-失败]
int Add_beam(Board *bd, int xpos, int color);

// 判断是否结棋
int Finish(Board *bd);

// TODO 悔棋 
void Rollback(Board *bd, HisA his);

// **查看对弈历史是 CLI 该做的事情。**