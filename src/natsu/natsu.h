// Natsu 是负责提供简便工具函数、协调各库、环境和 OS 的「胶水库」
#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

// 棋盘类 struct 声明
// 历史记录
struct _HistoryA
{
	// TODO
};
typedef struct _HistoryA HisA;
// 盘面
struct _Board
{
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
// 创建 CBoard 的结果
struct _CreateResult
{
	// 创建成功返回 1
	// 内存空间不足返回 -1
	int result;
	Board bd;
};
typedef struct _CreateResult CreateResult;

// 函数

// 阻塞式等待键盘输入字符，即时响应
// 并匹配 req 中的字符
// 匹配成功则返回其在 req 中的下标，从 0 开始
// 如果传入 _ 代表一个通配符，匹配除其余指明字符外的所有字符。
int Get_single_key_input(char *req);

void Change_window_size(int height, int width);

void HelloNatsu();