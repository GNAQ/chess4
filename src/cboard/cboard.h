// 创建一个棋盘，并处理棋盘操作
// 处理历史记录的增减
// “核心交互库”。

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "../natsu/natsu.h"

void HelloCBoard();

// 创建一条历史，[1] 写入当前时间 / [0] 时间初始为 NULL
CreateHisA* Create_HisA(int write_cur_time);

// 创建一个棋盘 h by w
CreateResult* Create_chessboard(int height, int width, char *usrA, char *usrB, int idA, int idB);

// 删除一个棋盘
void Destroy_chessboard(CreateResult *result);

// 删除一条历史记录
void Destroy_HisA(HisA *his);

// 添加一个子 [1 成功 || 0 满格-失败]
int Add_beam(Board *bd, int xpos, int color);

// 判断是否结棋
int Finish(Board *bd);
