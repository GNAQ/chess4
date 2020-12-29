// 处理命令行显示的相关内容
// “显示库”

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

#include "../natsu/natsu.h"

void HelloCli();

// 展示游戏规则
void Show_rules();

// 展示对弈棋盘
void Show_board(Board *bd, int cursorpos, int goer);

// 展示历史记录界面
void Show_hisA(Board* bd, HisA *his, int cnt_pos);

int Show_his_list(int sel);